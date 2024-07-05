#ifndef SPELLCHECKER_H
#define SPELLCHECKER_H

#include <string>

namespace sdds {

class SpellChecker {
public:
  SpellChecker() = default;
  SpellChecker(const char *filename);
  SpellChecker(SpellChecker &&) = default;
  SpellChecker(const SpellChecker &) = default;
  SpellChecker &operator=(SpellChecker &&) = default;
  SpellChecker &operator=(const SpellChecker &) = default;
  ~SpellChecker() = default;

  void operator()(std::string &text);
  void showStatistics(std::ostream &out) const;

private:
  std::string m_badWords[6];
  std::string m_goodWords[6];
  size_t m_count[6];
};
} // namespace sdds

#endif // !SPELLCHECKER_H
