#include "Movie.h"
#include "Book.h"
#include <iomanip>

namespace sdds {

const std::string &Movie::title() const { return m_title; }

// TITLE,YEAR,DESCRIPTION
Movie::Movie(const std::string &strMovie) : Movie() {
  size_t commaIndex = strMovie.find(',');
  size_t currentIndex = commaIndex + 1;
  std::string value = strMovie.substr(0, commaIndex);
  trim(value);
  m_title = value;
  commaIndex = strMovie.find(',', currentIndex);
  value = strMovie.substr(currentIndex, commaIndex - currentIndex);
  trim(value);
  m_yearReleased = stoi(value);
  currentIndex = commaIndex + 1;
  commaIndex = strMovie.find(',', currentIndex);
  value = strMovie.substr(currentIndex);
  trim(value);
  m_description = value;
}

std::ostream &operator<<(std::ostream &os, const Movie &movie) {
  using std::right;
  using std::setw;

  os << right << setw(40) << movie.m_title << " | ";
  os << right << setw(4) << movie.m_yearReleased << " | ";
  os << movie.m_description << std::endl;

  return os;
}

} // namespace sdds
