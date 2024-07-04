#include "SpellChecker.h"

#include <fstream>
#include <iomanip>

namespace sdds {

SpellChecker::SpellChecker(const char *filename) {
  std::ifstream file(filename);
  if (file.is_open()) {
    size_t index = 0;
    std::string goodWord;
    std::string badWord;
    while (file >> badWord >> goodWord) {
      m_badWords[index] = badWord;
      m_goodWords[index++] = goodWord;
    }
    file.close();
  } else {
    throw "Bad file name!";
  }
}

void SpellChecker::operator()(std::string &text) {
  for (size_t i = 0; i < 6; i++) {
    while (text.find(m_badWords[i]) != std::string::npos) {
      text.replace(text.find(m_badWords[i]), m_badWords[i].length(),
                   m_goodWords[i]);
      m_count[i]++;
    }
  }
}

void SpellChecker::showStatistics(std::ostream &out) const {
  out << "Spellchecker Statistics\n";
  for (size_t i = 0; i < 6; i++) {
    out << std::right << std::setw(15) << m_badWords[i] << ": " << m_count[i]
        << " replacements\n";
  }
}

} // namespace sdds
