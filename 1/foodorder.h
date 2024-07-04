#ifndef food_order_h
#define food_order_h

#include <iostream>

extern double g_taxrate;
extern double g_dailydiscount;

namespace sdds {

class FoodOrder {
public:
  FoodOrder();                             // default constructor
  FoodOrder(const FoodOrder &);            // copy constructor
  FoodOrder &operator=(const FoodOrder &); // copy assignment operator
  ~FoodOrder();                            // destructor
  void read(std::istream &input);          // read function
  void display() const;                    // display function

private:
  char m_name[10];
  char *m_descript;
  double m_price;
  bool m_isSpecial;
};

} // namespace sdds

#endif
