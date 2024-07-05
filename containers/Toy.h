#ifndef TOY_H
#define TOY_H

#include <iostream>
using std::ostream;
using std::string;

namespace sdds {

class Toy {
public:
  Toy();
  Toy(const string &toy);

  void update(int numItems);
  friend ostream &operator<<(ostream &os, const Toy &Toy);

private:
  size_t m_id;
  string m_name;
  size_t m_numToys;
  double m_price;
  static constexpr double m_tax = 0.13;
};

} // namespace sdds

#endif // !TOY_H
