#ifndef MOVIE_H
#define MOVIE_H

#include <string>
namespace sdds {

class Movie {
public:
  Movie() : m_title{""}, m_yearReleased{0}, m_description{""} {};
  Movie(Movie &&) = default;
  Movie(const Movie &) = default;
  Movie &operator=(Movie &&) = default;
  Movie &operator=(const Movie &) = default;
  ~Movie() = default;

  const std::string &title() const;
  Movie(const std::string &strMovie);

  template <class T> void fixSpelling(T &spellChecker) {
    spellChecker(m_title);
    spellChecker(m_description);
  }

  friend std::ostream &operator<<(std::ostream &os, const Movie &movie);

private:
  std::string m_title;
  size_t m_yearReleased;
  std::string m_description;
};

} // namespace sdds

#endif // !MOVIE_H
