#ifndef collection_h
#define collection_h

#include "Pair.h"
#include <iomanip>
#include <iostream>
namespace sdds {

template <class T, size_t CAPACITY> class Collection {
public:
  size_t size() { return m_count; }
  virtual ~Collection() {}
  void display(std::ostream &os = std::cout) {
    using std::endl;
    using std::setfill;
    using std::setw;

    os << setw(22) << setfill('-') << "" << endl;
    os << "| Collection Content |" << endl;
    os << setw(22) << setfill('-') << "" << endl;
    for (size_t i = 0; i < m_count; i++) {
      os << setfill(' ') << m_items[i] << endl;
    }
    os << setw(22) << setfill('-') << "" << endl;
  }
  virtual bool add(const T &item) {
    if (m_count < CAPACITY) {
      m_items[m_count++] = item;
      return true;
    }
    return false;
  }
  T operator[](size_t i) { return i < m_count ? m_items[i] : m_dummy; };

private:
  const static T m_dummy;
  size_t m_count{0};
  T m_items[CAPACITY]{}; // Holds the array of items in the queue.
};

template <typename T, std::size_t CAPACITY>
const T Collection<T, CAPACITY>::m_dummy = T{};

template <>
inline const Pair Collection<Pair, 100u>::m_dummy = Pair("No Key", "No Value");
} // namespace sdds

#endif // !collection_h
