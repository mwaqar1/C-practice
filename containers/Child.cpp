#include "Child.h"

namespace sdds {

Child::Child() : m_name{}, m_age{0}, m_toy{nullptr}, m_toyCount{0} {}

Child::~Child() { destruct(); }

Child::Child(const Child &C) : Child() { *this = C; }

Child::Child(Child &&C) : Child() { *this = std::move(C); }

Child &Child::operator=(Child &&C) {
  if (this != &C) {
    destruct();
    m_name = std::move(C.m_name);
    m_age = C.m_age;
    m_toyCount = C.m_toyCount;
    m_toy = C.m_toy;
    C.m_toyCount = 0;
    C.m_age = 0;
    C.m_toy = nullptr;
  }
  return *this;
}
Child &Child::operator=(const Child &C) {
  if (this != &C) {
    destruct();
    m_name = C.m_name;
    m_age = C.m_age;
    m_toyCount = C.m_toyCount;
    m_toy = new const Toy *[m_toyCount];
    for (size_t i = 0; i < m_toyCount; i++) {
      m_toy[i] = new Toy(*C.m_toy[i]);
    }
  }
  return *this;
}

Child::Child(string name, int age, const Toy *toys[], size_t count)
    : m_name{name}, m_age{age}, m_toyCount{count} {
  m_toy = new const Toy *[m_toyCount];
  for (size_t i = 0; i < m_toyCount; i++) {
    m_toy[i] = new Toy(*toys[i]);
  }
}

ostream &operator<<(ostream &os, const Child &C) {

  static size_t CALL_CNT = 0;
  os << "--------------------------" << std::endl;
  os << "Child " << ++CALL_CNT << ": " << C.m_name << " " << C.m_age
     << " years old:" << std::endl;
  os << "--------------------------" << std::endl;

  if (!C.m_toyCount) {
    os << "This child has no toys!" << std::endl;
  }

  else {
    for (size_t i = 0; i < C.m_toyCount; i++) {
      if (C.m_toy[i])
        os << *C.m_toy[i];
    }
  }

  os << "--------------------------" << std::endl;
  return os;
}

void Child::destruct() {
  if (m_toy != nullptr) {
    for (size_t i = 0; i < m_toyCount; i++) {
      if (m_toy[i] != nullptr) {
        delete m_toy[i];
        m_toy[i] = nullptr;
      }
    }
  }
  delete[] m_toy;
  m_toy = nullptr;
}

} // namespace sdds
