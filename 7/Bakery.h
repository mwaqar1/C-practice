#ifndef SDDS_BAKERY_H
#define SDDS_BAKERY_H

#include <list>
#include <ostream>
#include <vector>

namespace sdds {

enum class BakedType {
  BREAD,
  PASTERY,
};

struct BakedGood {
  BakedType m_type;
  std::string m_description;
  int m_life;
  int m_quantity;
  double m_price;
};

class Bakery {
public:
  Bakery() = default;
  Bakery(std::string filename);
  Bakery(Bakery &&) = default;
  Bakery(const Bakery &) = default;
  Bakery &operator=(Bakery &&) = default;
  Bakery &operator=(const Bakery &) = default;
  ~Bakery() = default;

  void showGoods(std::ostream &os) const;
  void sortBakery(std::string sortBy);
  std::vector<BakedGood> combine(Bakery &b);
  bool inStock(std::string description, BakedType type) const;
  std::list<BakedGood> outOfStock(BakedType type) const;

  std::vector<BakedGood> m_goods;

private:
  std::string trim(const std::string &str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
  }
};

std::ostream &operator<<(std::ostream &out, const BakedGood &b);

} // namespace sdds

#endif // !SDDS_BAKERY_H
