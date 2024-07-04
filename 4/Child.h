#ifndef CHILD_H
#define CHILD_H

#include "Toy.h"

namespace sdds {
class Child {
public:
  Child();
  Child(string name, int age, const Toy *toys[], size_t count);
  Child(Child &&C);
  Child(const Child &C);
  Child &operator=(Child &&C);
  Child &operator=(const Child &C);
  ~Child();

  size_t size() const;

  friend ostream &operator<<(ostream &os, const Child &C);

private:
  string m_name;
  int m_age;
  const Toy **m_toy;
  size_t m_toyCount;
  void destruct();
};

} // namespace sdds

#endif // !CHILD_H
