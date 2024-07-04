#include "foodorder.h" //CHANGE TO foodorde and rename header and cpp files from 2 ??
#include <cstring>
#include <iomanip>
#include <string>

double g_taxrate{};
double g_dailydiscount{};

namespace sdds {

// default constructor definition
FoodOrder::FoodOrder()
    : m_name{}, m_descript{nullptr}, m_price{}, m_isSpecial{false} {}

// copy constructor definition
FoodOrder::FoodOrder(const FoodOrder &foodOrder) : FoodOrder() {

  *this = foodOrder;
}

FoodOrder &FoodOrder::operator=(
    const FoodOrder &foodOrder) // copy assignment operator definition
{
  if (this != &foodOrder && foodOrder.m_descript) {

    if (this->m_descript != nullptr && m_descript) {
      delete[] this->m_descript;
      this->m_descript = nullptr;
    }

    this->m_descript = new char[strlen(foodOrder.m_descript) + 1];
    strcpy(this->m_descript, foodOrder.m_descript);

    strcpy(this->m_name, foodOrder.m_name);

    this->m_price = foodOrder.m_price;
    this->m_isSpecial = foodOrder.m_isSpecial;
  }
  return *this;
}

FoodOrder::~FoodOrder() {
  delete[] m_descript;
  m_descript = nullptr;
}

void FoodOrder::read(std::istream &input) {
  if (input.good()) {
    char status{};
    std::string desc{};

    input.get(m_name, 10, ',');
    input.ignore();
    std::getline(input, desc, ',');

    if (desc.length() > 0) {
      if (m_descript != nullptr &&
          m_descript) { // if m_descript does not have a garbage value
                        // and its not a null pointer
        delete[] m_descript;
        m_descript = nullptr;
      }
      m_descript = new char[desc.length() + 1];
      strcpy(m_descript, desc.c_str());
    } else
      return;

    input >> this->m_price;
    input.ignore();
    input >> status;
    m_isSpecial = status == 'Y' ? true : false;
  }
}

void FoodOrder::display() const {

  static unsigned int counter = 0;
  counter++; // increment each time function is called
  std::string temp{};
  double priceWithTax = (g_taxrate + 1) * m_price;

  std::cout << std::setw(2) << std::left << counter << ". ";

  if (m_name[0] !=
      '\0') { // check to see whether the name character array is empty

    std::cout << std::setw(10) << std::left << m_name << "|";
    std::cout << std::setw(25) << std::left << m_descript << "|";
    std::cout << std::setw(12) << std::left << std::fixed
              << std::setprecision(2) << priceWithTax << "|";

    if (m_isSpecial) { // name is not empty
      std::cout << std::setw(13) << std::right
                << priceWithTax - g_dailydiscount;
    }

  } else { // if name is empty

    std::cout << "No Order";
  }

  std::cout << std::endl;
}

} // namespace sdds
