#include "Bakery.h"
#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <numeric>

namespace sdds {

// BakedType Description ShelfLife Stock Price
// by breaking it down into smaller steps, i.e make
// temp BakedGood, then set the values of the temp, then push_back the temp into
// m_goods
Bakery::Bakery(std::string filename) {
  std::ifstream file(filename);
  if (!file) {
    throw "File not found";
  }
  std::string line;
  std::string type, description, life, stock, price;

  while (std::getline(file, line)) {
    std::string typeStr = trim(line.substr(0, 8));
    BakedType type;
    if (typeStr == "Bread") {
      type = BakedType::BREAD;
    } else if (typeStr == "Pastry") {
      type = BakedType::PASTERY;
    } else {
      throw "Invalid type, only Bread and Pastry are allowed";
    }
    std::string description = trim(line.substr(8, 20));
    std::string shelfLife = trim(line.substr(28, 14));
    std::string stock = trim(line.substr(42, 8));
    std::string price = trim(line.substr(50, 6));

    m_goods.push_back(BakedGood{type, description, std::stoi(shelfLife),
                                std::stoi(stock), std::stod(price)});
  }
}

void Bakery::showGoods(std::ostream &os) const {
  // STL for each
  auto print = [&os](const BakedGood &b) { os << b << std::endl; };
  std::for_each(m_goods.begin(), m_goods.end(), print);

  auto totalStockCalculator = [](int sum, const BakedGood &b) -> size_t {
    sum += b.m_quantity;
    return sum;
  };

  auto totalPriceCalculator = [](const BakedGood &b) -> double {
    return b.m_price;
  };

  // they do the same thing (get the sum of price and stock) I would've used
  // accumulate for both (because its more commonly used) but we weren't allowed
  // to use the same alogrithm twice

  // STL transform_reduce

  auto totalPrice = std::transform_reduce(m_goods.begin(), m_goods.end(), 0.0,
                                          std::plus<>(), totalPriceCalculator);

  // STL acucmulate
  auto totalStock =
      std::accumulate(m_goods.begin(), m_goods.end(), 0, totalStockCalculator);

  os << "Total Stock: " << totalStock << std::endl;
  os << "Total Price: " << totalPrice << std::endl;
}

std::ostream &operator<<(std::ostream &out, const BakedGood &b) {
  std::string type = b.m_type == BakedType::BREAD ? "Bread" : "Pastry";

  out << "* " << std::left << std::setw(10) << type << " * " << std::left
      << std::setw(20) << b.m_description << " * " << std::setw(5) << b.m_life
      << " * " << std::setw(5) << b.m_quantity << " * " << std::fixed
      << std::setprecision(2) << std::right << std::setw(8) << b.m_price
      << " * ";
  return out;
}

void Bakery::sortBakery(std::string sortBy) {
  auto compare = [sortBy](const BakedGood &a, const BakedGood &b) {
    int result = 0;
    if (sortBy == "Price") {
      result = a.m_price < b.m_price;
    } else if (sortBy == "Stock") {
      result = a.m_quantity < b.m_quantity;
    } else if (sortBy == "Shelf") {
      result = a.m_life < b.m_life;
    } else if (sortBy == "Description") {
      result = a.m_description < b.m_description;
    } else {
      throw "Invalid sort type";
    }

    return result;
  };
  // STL algorithm it sorts
  std::sort(m_goods.begin(), m_goods.end(), compare);
}

std::vector<BakedGood> Bakery::combine(Bakery &b) {
  b.sortBakery("Price");
  sortBakery("Price");
  auto mergeSort = [](const BakedGood &a, const BakedGood &b) {
    return a.m_price < b.m_price;
  };
  std::vector<BakedGood> combined_goods(m_goods.size() + b.m_goods.size());
  // STL algorthm merge (alternative is set_union) used merge because with merge
  // you can give it a lambda function
  //  to sort the output but set union only takes a pre-sorted container
  std::merge(m_goods.begin(), m_goods.end(), b.m_goods.begin(), b.m_goods.end(),
             combined_goods.begin(), mergeSort);

  return combined_goods;
}

bool Bakery::inStock(std::string description, BakedType type) const {
  auto inStock = [description, type](const BakedGood &b) {
    return b.m_description == description && b.m_type == type && b.m_quantity;
  };

  // stl any_of used because i just wanted to check what was in stock so
  // anything that matched my condition was in the stock.
  return std::any_of(m_goods.begin(), m_goods.end(), inStock);
}

std::list<BakedGood> Bakery::outOfStock(BakedType type) const {
  std::list<BakedGood> outOfStock;

  auto isItOut = [type](const BakedGood &b) {
    return b.m_type == type && !b.m_quantity;
  };

  // STL alogrithm copy_if I used it to populate a new list and that new list
  // only added new elements if it was out of stock (if passed a certain
  // condition i.e. quantity ==0 and the type was the same) then we populated
  // the new list with the elements of our m_goods vector. So we used copy_if to
  // conditionally populate instead of copying everything then removing elements
  std::copy_if(m_goods.begin(), m_goods.end(), std::back_inserter(outOfStock),
               isItOut);
  return outOfStock;
}

} // namespace sdds
