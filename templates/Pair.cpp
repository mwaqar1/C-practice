#include "Pair.h"

namespace sdds {

bool Pair::operator==(const Pair &p) const { return this->m_key == p.m_key; };

std::ostream &operator<<(std::ostream &os, const Pair &obj) {
  os << std::setw(20) << std::right << obj.m_key << ": " << std::left
     << obj.m_value;
  return os;
}
} // namespace sdds
