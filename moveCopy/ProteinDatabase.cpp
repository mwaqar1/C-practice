#include "ProteinDatabase.h"

namespace sdds {

ProteinDatabase::ProteinDatabase() : m_proteinPointer{}, m_size{} {};

ProteinDatabase::ProteinDatabase(const char *filename) : ProteinDatabase() {
  // Open the file
  std::ifstream file(filename);

  // Count the number of proteinhs in the file
  std::string line;
  while (std::getline(file, line)) {
    if (line[0] == '>') {
      m_size++;
    }
  }

  // Allocate memory for the protein sequences
  m_proteinPointer = new std::string[m_size + 1];

  // Go back to the beginning of the file
  file.clear();
  file.seekg(0, std::ios::beg);

  // Load the protein sequences into the array
  size_t proteinIndex = 0;
  std::string protein;
  while (std::getline(file, line)) {
    if (line[0] == '>') {
      if (!protein.empty()) {
        m_proteinPointer[proteinIndex] = protein;
        proteinIndex++;
        protein.clear();
      }
    } else {
      protein += line;
    }
  }

  // Add the last protein sequence
  if (!protein.empty()) {
    m_proteinPointer[proteinIndex] = protein;
  }

  // Close the file
  file.close();
}

std::size_t ProteinDatabase::size() { return m_size; }

std::string ProteinDatabase::operator[](size_t indexPassed) {

  return indexPassed < m_size ? m_proteinPointer[indexPassed] : "";
}

ProteinDatabase::ProteinDatabase(const ProteinDatabase &other) {
  *this = other;
}
ProteinDatabase &ProteinDatabase::operator=(const ProteinDatabase &other) {
  if (this != &other && other.m_proteinPointer) {

    if (m_proteinPointer != nullptr && m_proteinPointer) {
      delete[] m_proteinPointer;
      m_proteinPointer = nullptr;
    }
    m_size = other.m_size;
    m_proteinPointer = new std::string[m_size];

    for (size_t i = 0; i < m_size; i++) {
      m_proteinPointer[i] = other.m_proteinPointer[i];
    }
  }
  return *this;
}

ProteinDatabase::~ProteinDatabase() { delete[] m_proteinPointer; }

ProteinDatabase::ProteinDatabase(ProteinDatabase &&other) : ProteinDatabase() {

  *this = std::move(other);
}

ProteinDatabase &ProteinDatabase::operator=(ProteinDatabase &&other) {

  if (this != &other && other.m_proteinPointer) {

    if (m_proteinPointer != nullptr && m_proteinPointer) {
      delete[] m_proteinPointer;
      m_proteinPointer = nullptr;
    }

    m_size = other.m_size;
    m_proteinPointer = other.m_proteinPointer;
    other.m_proteinPointer = nullptr;
    other.m_size = 0;
  }

  return *this;
}
} // namespace sdds
