#include "ConfirmOrder.h"
#include <iostream>

namespace sdds {

int ConfirmOrder::toyIsInOrder(const Toy &toy) const {
  int index = -1;
  for (size_t i = 0; i < m_toyCount; i++) {
    if (m_toy[i] == &toy) {
      index = i;
      break; // optional, if you remove this break, the function will do exactly
             // the same thing still but it will take longer, because the loop
             // will finish even if we found a match.
    }
  }
  return index;
}

ConfirmOrder::ConfirmOrder() : m_toy{nullptr}, m_toyCount{0} {}
ConfirmOrder::ConfirmOrder(ConfirmOrder &&CO) { *this = std::move(CO); }
ConfirmOrder::ConfirmOrder(const ConfirmOrder &CO) { *this = CO; }

ConfirmOrder &ConfirmOrder::operator=(ConfirmOrder &&CO) {
  if (this != &CO) {
    m_toy = CO.m_toy;
    m_toyCount = CO.m_toyCount;
    CO.m_toy = nullptr;
    CO.m_toyCount = 0;
  }
  return *this;
}

ConfirmOrder &ConfirmOrder::operator=(const ConfirmOrder &CO) {
  if (this != &CO) {
    m_toy = new const Toy *[CO.m_toyCount];
    m_toyCount = CO.m_toyCount;
    for (size_t i = 0; i < m_toyCount; i++) {
      m_toy[i] = CO.m_toy[i];
    }
  }
  return *this;
}

ConfirmOrder::~ConfirmOrder() {
  delete[] m_toy;
  m_toy = nullptr;
}

ConfirmOrder &ConfirmOrder::operator+=(const Toy &toy) {
  if (toyIsInOrder(toy) == -1) {
    const Toy **temp = new const Toy *[m_toyCount + 1];
    for (size_t i = 0; i < m_toyCount; i++) {
      temp[i] = m_toy[i];
    }
    temp[m_toyCount] = &toy;
    delete[] m_toy;
    m_toy = temp;
    m_toyCount++;
  }
  return *this;
}

ConfirmOrder &ConfirmOrder::operator-=(const Toy &toy) {
  int index = toyIsInOrder(toy);
  if (index != -1) {
    const Toy **temp = new const Toy *[m_toyCount - 1];
    for (int i = 0; i < (int)m_toyCount; i++) {
      if (i < index) {
        temp[i] = m_toy[i];
      } else if (i > index) {
        temp[i - 1] = m_toy[i];
      }
    }
    delete[] m_toy;
    m_toy = temp;
    m_toyCount--;
  }
  return *this;
}
ostream &operator<<(ostream &os, const ConfirmOrder &CO) {
  os << "--------------------------" << std::endl;
  os << "Confirmations to Send" << std::endl;
  os << "--------------------------" << std::endl;

  if (CO.m_toyCount) {
    for (size_t i = 0; i < CO.m_toyCount; i++) {
      os << *CO.m_toy[i];
    }
  } else {
    os << "There are no confirmations to send!" << std::endl;
  }
  os << "--------------------------" << std::endl;

  return os;
}

} // namespace sdds
