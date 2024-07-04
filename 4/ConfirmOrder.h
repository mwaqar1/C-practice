#ifndef CONFIRMORDER_H
#define CONFIRMORDER_H

#include "Toy.h"

namespace sdds {
class ConfirmOrder {
public:
  ConfirmOrder();
  ConfirmOrder(ConfirmOrder &&);
  ConfirmOrder(const ConfirmOrder &);
  ConfirmOrder &operator=(ConfirmOrder &&);
  ConfirmOrder &operator=(const ConfirmOrder &);
  ~ConfirmOrder();
  ConfirmOrder &operator+=(const Toy &toy);
  ConfirmOrder &operator-=(const Toy &toy);

  friend ostream &operator<<(ostream &os, const ConfirmOrder &CO);

private:
  const Toy **m_toy;
  size_t m_toyCount;
  int toyIsInOrder(const Toy &toy) const;
};

} // namespace sdds

#endif // !CONFIRMORDER_H
