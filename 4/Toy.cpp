#include "Toy.h"
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

void trim(string &str) {
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
Toy::Toy() : m_id{0}, m_name{}, m_numToys{0}, m_price{0.0} {}

// ID:NAME:NUM:PRICE
Toy::Toy(const string &toy) {
  size_t colonIndex = toy.find(':');
  size_t currentIndex = colonIndex + 1;
  string value = toy.substr(0, colonIndex);

  // trim(value);
  // std::cout << "m_id : " << value << std::endl;
  m_id = std::stoi(value);
  colonIndex = toy.find(':', currentIndex);
  value = toy.substr(currentIndex, colonIndex - currentIndex);
  trim(value);
  // std::cout << "m_name : " << value << std::endl;
  m_name = value;
  currentIndex = colonIndex + 1;
  colonIndex = toy.find(':', currentIndex);
  value = toy.substr(currentIndex, colonIndex - currentIndex);
  // trim(value);
  // std::cout << "m_numToys : " << value << std::endl;
  m_numToys = std::stoi(value);
  currentIndex = colonIndex + 1;
  colonIndex = toy.find(':', currentIndex);
  value = toy.substr(currentIndex, colonIndex - currentIndex);

  // std::cout << "m_price : " << value << std::endl;
  m_price = std::stod(value);
}

void Toy::update(int numItems) { m_numToys = numItems; }

ostream &operator<<(ostream &os, const Toy &Toy) {
  using std::fixed;
  using std::left;
  using std::right;
  using std::setprecision;
  using std::setw;
  const double subtotal = Toy.m_price * Toy.m_numToys;
  os << "Toy" << setw(8) << Toy.m_id << ":" << right << setw(18) << Toy.m_name
     << setw(3) << Toy.m_numToys << " items" << setw(8) << Toy.m_price
     << "/item  subtotal:" << setw(7) << subtotal << " tax:" << setw(6) << fixed
     << setprecision(2) << subtotal * Toy.m_tax << " total:" << setw(7) << fixed
     << setprecision(2) << subtotal * (1 + Toy.m_tax) << std::endl;
  return os;
}

} // namespace sdds
