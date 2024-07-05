#ifndef BOOK_H
#define BOOK_H

#include <string>

void trim(std::string &str);
namespace sdds {

class Book {
public:
  Book()
      : m_author{}, m_title{}, m_countryPublished{},
        m_yearPublished{0}, m_price{0}, m_description{} {};
  Book(const std::string &strBook);
  Book(Book &&) = default;
  Book(const Book &) = default;
  Book &operator=(Book &&) = default;
  Book &operator=(const Book &) = default;
  ~Book() = default;

  const std::string &title() const;
  const std::string &country() const;
  const size_t &year() const;
  double &price();

  friend std::ostream &operator<<(std::ostream &, const Book &);

  template <typename T> void fixSpelling(T &spellChecker) {
    spellChecker(m_description);
  }

private:
  std::string m_author;
  std::string m_title;
  std::string m_countryPublished;
  size_t m_yearPublished;
  double m_price;
  std::string m_description;
};

} // namespace sdds

#endif // !BOOK_H
