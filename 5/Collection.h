// Maham Waqar
// mwaqar4@myseneca.ca
// 127044196
// Sun, 19 Feb 2023
// I have done all the coding by myself and only copied the code that my
// professor provided to complete my workshops and assignments.

#ifndef COLLECTION_H
#define COLLECTION_H

#include <ostream>
namespace sdds {
template <typename T> class Collection {
public:
  Collection()
      : m_name{""}, m_collection{nullptr}, m_size{0}, observer{nullptr} {};
  Collection(const std::string &name) : Collection() { m_name = name; }
  Collection(Collection &&) = default;
  Collection(const Collection &) = delete;
  Collection &operator=(Collection &&) = default;
  Collection &operator=(const Collection &) = delete;
  ~Collection() {
    delete[] m_collection;
    m_collection = nullptr;
  }
  const std::string &name() const { return m_name; }
  size_t size() const { return m_size; }
  void setObserver(void (*observer)(const Collection<T> &, const T &)) {
    this->observer = observer;
  }
  Collection<T> &operator+=(const T &item) {
    if ((*this)[item.title()] == nullptr) {
      T *temp = new T[m_size + 1];
      for (size_t i = 0; i < m_size; i++) {
        temp[i] = m_collection[i];
      }
      delete[] m_collection;
      m_collection = temp;
      m_collection[m_size++] = item;
      if (this->observer) {
        this->observer(*this, item);
      }
    }
    return *this;
  }

  T &operator[](size_t idx) const {

    if (idx >= m_size) {
      throw std::out_of_range("Bad index [" + std::to_string(idx) +
                              "]. Collection has [" + std::to_string(m_size) +
                              "] items.");
    }
    return m_collection[idx];
  }
  T *operator[](const std::string &title) const {
    bool found = false;
    T *result = nullptr;
    for (size_t i = 0; i < m_size && !found; i++) {
      if (m_collection[i].title() == title) {
        result = &m_collection[i];
        found = true;
      }
    }
    return result;
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const Collection<T> &collection) {
    for (size_t i = 0; i < collection.size(); i++) {
      os << collection[i];
    }
    return os;
  }

private:
  std::string m_name;
  T *m_collection;
  size_t m_size;
  void (*observer)(const Collection<T> &collection, const T &item);
};
} // namespace sdds

#endif // !COLLECTION_H
