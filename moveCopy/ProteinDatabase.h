#ifndef protein_database_h
#define protein_database_h

#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>

namespace sdds {

class ProteinDatabase {
public:
  ProteinDatabase();
  ProteinDatabase(const char *);
  ProteinDatabase(const ProteinDatabase &);
  ProteinDatabase(ProteinDatabase &&);
  ProteinDatabase &operator=(ProteinDatabase &&);

  ProteinDatabase &operator=(const ProteinDatabase &);
  ~ProteinDatabase();
  std::size_t size();
  std::string operator[](size_t);

private:
  std::string *m_proteinPointer{}; //  pointer to dynamically
                                   //  allocated string array
  size_t m_size{};                 // num of strings stored
};

} // namespace sdds
#endif
