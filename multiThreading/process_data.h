// Workshop 9 - Multi-Threading, Thread Class
// process_data.h
// 2021/1/5 - Jeevan Pant
/*
Name:Maham Waqar
email: mwaqar4@myseneca.ca
id: 127044196
date: 04/09/23
I have done all the coding by myself and only copied the code that my professor
provided to complete my workshops and assignments.*/

#ifndef SDDS_W9_PROCESSDATA_H
#define SDDS_W9_PROCESSDATA_H

#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <thread>
#include <vector>

namespace sdds_ws9 {
void computeAvgFactor(const int *, int, int, double &);
void computeVarFactor(const int *, int, int, double, double &);
class ProcessData {
  int total_items{};
  int *data{};
  // Following parameters are included to be used for managing multi-threaded
  //  computation in the operator() function.
  int num_threads{0};         // to hold number of threads
  double *averages{nullptr};  // to hold average factors
  double *variances{nullptr}; // to hold variance factors
  int *p_indices{nullptr};    // to hold partitioning indices
public:
  ProcessData(std::string, int n_threads);
  ProcessData(const ProcessData &) = delete;
  ProcessData &operator=(const ProcessData &) = delete;
  ~ProcessData();
  operator bool() const;
  int operator()(std::string, double &, double &);
};

} // namespace sdds_ws9

#endif
