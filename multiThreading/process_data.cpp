#include "process_data.h"
#include <mutex>

namespace sdds_ws9 {

void computeAvgFactor(const int *arr, int size, int divisor, double &avg) {
  avg = 0;
  for (int i = 0; i < size; i++) {
    avg += arr[i];
    std::this_thread::sleep_for(std::chrono::nanoseconds(1));
  }
  avg /= divisor;
}

void computeVarFactor(const int *arr, int size, int divisor, double avg,
                      double &var) {
  var = 0;
  for (int i = 0; i < size; i++) {
    var += (arr[i] - avg) * (arr[i] - avg);
    std::this_thread::sleep_for(std::chrono::nanoseconds(1));
  }
  var /= divisor;
}
ProcessData::operator bool() const {
  return total_items > 0 && data && num_threads > 0 && averages && variances &&
         p_indices;
}

ProcessData::ProcessData(std::string filename, int n_threads) {
  // TODO: Open the file whose name was received as parameter and read the
  // content
  //         into variables "total_items" and "data". Don't forget to allocate
  //         memory for "data".
  //       The file is binary and has the format described in the specs.
  std::ifstream file(filename, std::ios::binary);
  if (file) { // If the file is successfully opened
    // Read the total_items from the file
    file.read(reinterpret_cast<char *>(&total_items), sizeof(total_items));

    // Allocate memory for data array to hold total_items integers
    data = new int[total_items];

    file.read(reinterpret_cast<char *>(data), total_items * sizeof(int));

    std::cout << "Item's count in file '" << filename << "': " << total_items
              << std::endl;
    std::cout << "  [" << data[0] << ", " << data[1] << ", " << data[2]
              << ", ... , " << data[total_items - 3] << ", "
              << data[total_items - 2] << ", " << data[total_items - 1]
              << "]\n";

    // Following statements initialize the variables added for multi-threaded
    //   computation
    num_threads = n_threads;
    averages = new double[num_threads]{};
    variances = new double[num_threads]{};
    p_indices = new int[num_threads + 1]{};
    for (int i = 0; i < num_threads + 1; i++)
      p_indices[i] = i * (total_items / num_threads);
  }
}

ProcessData::~ProcessData() {
  delete[] data;
  delete[] averages;
  delete[] variances;
  delete[] p_indices;
}

// TODO: Improve operator() function from part-1 for multi-threaded operation.
// Enhance the
//   function logic for the computation of average and variance by running the
//   function computeAvgFactor and computeVarFactor in multile threads.
// The function divides the data into a number of parts, where the number of
// parts is
//   equal to the number of threads. Use multi-threading to compute
//   average-factor for each part of the data by calling the function
//   computeAvgFactor. Add the obtained average-factors to compute total
//   average. Use the resulting total average as the average value argument
//   for the function computeVarFactor, to compute variance-factors for each
//   part of the data. Use multi-threading to compute variance-factor for each
//   part of the data. Add computed variance-factors to obtain total variance.
// Save the data into a file with filename held by the argument fname_target.
// Also, read the workshop instruction.

int ProcessData::operator()(std::string filename, double &avg, double &var) {
  std::vector<double> avg_factors(num_threads);
  std::vector<double> var_factors(num_threads);

  std::vector<std::thread> threads;

  int items_per_thread = total_items / num_threads;

  for (int i = 0; i < num_threads; ++i) {
    int start = i * items_per_thread;
    int end = (i == num_threads - 1) ? total_items : start + items_per_thread;

    threads.emplace_back([this, i, start, end, &avg_factors]() {
      computeAvgFactor(data + start, end - start, total_items, avg_factors[i]);
    });
  }

  for (auto &thread : threads) {
    thread.join();
  }

  avg = 0;
  for (const auto &factor : avg_factors) {
    avg += factor;
  }

  threads.clear();

  for (int i = 0; i < num_threads; ++i) {
    int start = i * items_per_thread;
    int end = (i == num_threads - 1) ? total_items : start + items_per_thread;

    threads.emplace_back([this, i, start, end, &var_factors, avg]() {
      computeVarFactor(data + start, end - start, total_items, avg,
                       var_factors[i]);
    });
  }

  for (auto &thread : threads) {
    thread.join();
  }

  var = 0;
  for (const auto &factor : var_factors) {
    var += factor;
  }

  std::ofstream outFile(filename, std::ios::binary);
  if (outFile) {
    outFile.write(reinterpret_cast<const char *>(&total_items),
                  sizeof(total_items));
    outFile.write(reinterpret_cast<const char *>(data),
                  total_items * sizeof(int));
  }

  return 0;
}
} // namespace sdds_ws9
