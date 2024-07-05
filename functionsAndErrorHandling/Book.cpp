#include "Book.h"
#include <iomanip>

void trim(std::string &str) {
  int i = 0;
  int len = str.length();

  // NOTE: TRIMMING THE BEGINNING OF THE STRING

  // Find at which index the whitespace ends from the beginning
  while (len > i && std::isspace(str[i])) {
    i++;
  }
  // If there were any white spaces (means we went into the previous loop)
  if (i > 0) {
    str.erase(0, i); // remove the white spaces from beginning until we find a
                     // character that is not whitespace
  }
  len = str.length(); // update the size of len variable with the string's front
                      // trim
  i = len - 1;        // index of the end of the string

  // NOTE: TRIMMING THE END OF THE STRING

  // Find at which index the whitespace ends, going backwards from the end
  while (i >= 0 && std::isspace(str[i])) {
    i--;
  }
  if (i < len - 1) {
    str.erase(i + 1);
  }
}

namespace sdds {

const std::string &Book::country() const { return m_countryPublished; }
const std::string &Book::title() const { return m_title; }
const size_t &Book::year() const { return m_yearPublished; }
double &Book::price() { return m_price; }

// AUTHOR,TITLE,COUNTRY,PRICE,YEAR,DESCRIPTION
Book::Book(const std::string &strBook) : Book() {
  size_t commaIndex = strBook.find(',');
  size_t currentIndex = commaIndex + 1;
  std::string value = strBook.substr(0, commaIndex);
  trim(value);
  m_author = value;
  commaIndex = strBook.find(',', currentIndex);
  value = strBook.substr(currentIndex, commaIndex - currentIndex);
  trim(value);
  m_title = value;
  currentIndex = commaIndex + 1;
  commaIndex = strBook.find(',', currentIndex);
  value = strBook.substr(currentIndex, commaIndex - currentIndex);
  trim(value);
  m_countryPublished = value;
  currentIndex = commaIndex + 1;
  commaIndex = strBook.find(',', currentIndex);
  value = strBook.substr(currentIndex, commaIndex - currentIndex);
  m_price = stod(value);
  currentIndex = commaIndex + 1;
  commaIndex = strBook.find(',', currentIndex);
  value = strBook.substr(currentIndex, commaIndex - currentIndex);
  m_yearPublished = stoi(value);
  value = strBook.substr(commaIndex + 1);
  trim(value);
  m_description = value;
}

std::ostream &operator<<(std::ostream &os, const Book &B) {
  os << std::right << std::setw(20) << B.m_author << " | ";
  os << std::right << std::setw(22) << B.m_title << " | ";
  os << std::right << std::setw(5) << B.m_countryPublished << " | ";
  os << std::right << std::setw(4) << B.m_yearPublished << " | ";
  os << std::right << std::setw(6) << std::fixed << std::setprecision(2)
     << B.m_price << " | ";
  os << B.m_description << std::endl;

  return os;
}

// Book::Book(const std::string &strBook) {
//   std::string values[6];
//   size_t currentIndex = 0;
//   size_t commaIndex = 0;
//   int valueIndex = 0;

//   while (commaIndex != std::string::npos && valueIndex < 6) {
//     commaIndex = strBook.find(',', currentIndex);
//     std::string value = strBook.substr(currentIndex, commaIndex -
//     currentIndex); trim(value); values[valueIndex++] = value; currentIndex =
//     commaIndex + 1;
//   }

//   m_author = values[0];
//   m_title = values[1];
//   m_countryPublished = values[2];
//   m_price = stod(values[3]);
//   m_yearPublished = stoi(values[4]);
//   m_description = values[5];
// }

} // namespace sdds
