#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>

namespace sdds {

enum class Err_Status {
  Err_Success,
  Err_NotFound,
  Err_OutOfMemory,
};

template <typename T> //
class Database {
public:
  ~Database();

  // TODO: explain this in reflection, why shared_ptr
  static std::shared_ptr<Database> getInstance(const std::string &filename);
  Err_Status GetValue(const std::string &key, T &value);
  Err_Status SetValue(const std::string &key, const T &value);

private:
  Database(const std::string &filename);
  static std::shared_ptr<Database> m_instance;
  void encryptDecrypt(T &data);

  size_t m_numEntries;
  std::string m_keys[20];
  T m_values[20];
  std::string m_filename;
};

template <> //
inline void Database<std::string>::encryptDecrypt(std::string &value) {
  const char secret[]{"secret encryption key"};
  for (auto &c : value) {
    for (char k : secret) {
      c ^= k;
    }
  }
}

template <> //
inline void Database<long long>::encryptDecrypt(long long &value) {
  const char secret[]{"super secret encryption key"};
  char *bytes = reinterpret_cast<char *>(&value);

  for (std::size_t i = 0; i < sizeof(value); i++) {
    for (char k : secret) {
      bytes[i] ^= k;
    }
  }
}
// initialize static members outside the class
template <typename T>
std::shared_ptr<Database<T>> Database<T>::m_instance = nullptr;

template <typename T> Database<T>::Database(const std::string &filename) {
  m_filename = filename;
  m_numEntries = 0;
  std::cout << "[" << &m_filename << "] Database(const std::string&)"
            << std::endl;

  std::ifstream file(filename);
  std::string key, value_str;

  while (std::getline(file, key, ' ') && std::getline(file, value_str)) {
    std::replace(key.begin(), key.end(), '_', ' ');
    m_keys[m_numEntries] = key;

    T value;
    std::istringstream value_stream(value_str);
    value_stream >> value;

    encryptDecrypt(value);
    m_values[m_numEntries] = value;
    m_numEntries++;
  }

  file.close();
}

template <typename T>
std::shared_ptr<Database<T>>
Database<T>::getInstance(const std::string &filename) {
  if (m_instance == nullptr) {
    m_instance = std::shared_ptr<Database<T>>(new Database<T>(filename));
  }
  return m_instance;
}

// because we're not allowed multiple returns... can clean it up with if/else
template <typename T>
Err_Status Database<T>::GetValue(const std::string &key, T &value) {
  // find returns an iterator to the first element that matches the key
  // (it is a string pointer in this case)
  // essentially, the pointer is pointing to the first occurence of the value we
  // search for
  auto it = std::find(m_keys, m_keys + m_numEntries, key);
  // if the iterator is not at the end of the array, we found the key
  // the condition is checking to make sure the it isn't pointing to the end of
  // string if it is, then we didn't find the key then in the m_values[it -
  // m_keys] the index is calculated by subtracting the beginning of the array
  // from the iterator, which gives us the index of the key in the array

  return (it != m_keys + m_numEntries)
             ? (value = m_values[it - m_keys], Err_Status::Err_Success)
             : Err_Status::Err_NotFound;
}

// Err_Status Database::SetValue(const std::string &key,
//                               const std::string &value) {
//   // Check if there is space in the database to add the new key/value pair
//   if (m_numEntries < 20) {
//     // Add the new key/value pair to the end of the arrays
//     m_keys[m_numEntries] = key;
//     m_values[m_numEntries] = value;
//     m_numEntries++;
//     return Err_Status::Err_Success;
//   } else {
//     // If the database is full, return an error status code
//     return Err_Status::Err_OutOfMemory;
//   }
// }

// same as the above function, but using ternary operators for single return

template <typename T>
Err_Status Database<T>::SetValue(const std::string &key, const T &value) {
  // Check if there is space in the database to add the new key/value pair
  return (m_numEntries < 20)
             ? (m_keys[m_numEntries] = key, m_values[m_numEntries] = value,
                m_numEntries++, Err_Status::Err_Success)
             : Err_Status::Err_OutOfMemory;
}

// writing to a new file here with ofstream. ofstream opens a file to
// write things in it, the way it is created is line 91, essentially calling
// constructor of ofstream and the variable for its object in this case is
// called file
// by adding .bkp.txt to the filename, we are creating a new file with the same
// name as the original file, but with .bkp.txt at the end, which is what they
// asked. After that I can use the file the same way as cout, instead of
// terminal, the same output goes into the file
template <typename T> //
Database<T>::~Database() {
  std::cout << "[" << &m_filename << "] ~Database()" << std::endl;
  std::ofstream file(m_filename + ".bkp.txt");
  for (size_t i = 0; i < m_numEntries; i++) {
    encryptDecrypt(m_values[i]);
    file << std::setw(25) << std::left << m_keys[i] << " -> " << m_values[i]
         << std::endl;
  }
  file.close();
}

} // namespace sdds

#endif // !SDDS_DATABASE_H
