#ifndef set_h
#define set_h

#include "Collection.h"
#include <cmath>

namespace sdds {

template <class T> class Set : public Collection<T, 100u> {
public:
  bool add(const T &item) {
    bool unique = true;
    for (size_t i = 0; i < Collection<T, 100u>::size(); i++) {
      if (item == (*this)[i]) {
        unique = false;
      }
    }
    if (unique) {
      return Collection<T, 100u>::add(item);
    }
    return false;
  }

  using Collection<T, 100u>::operator[];
};

template <> inline bool Set<double>::add(const double &item) {
  using std::fabs;
  bool unique = true;

  for (size_t i = 0; i < Collection<double, 100u>::size(); i++) {
    if (fabs(item) <= (*this)[i] + 0.01 && fabs(item) >= (*this)[i] - 0.01) {
      unique = false;
    }
  }
  if (unique) {
    return Collection<double, 100u>::add(item);
  }
  return false;
}

} // namespace sdds
#endif // !set_h
