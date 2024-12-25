#include <chrono>
#include <iostream>
// #include <stdexcept>
#include <fstream>
#include <streambuf>
#include <thread>
#include <vector>

using namespace std;

using chrono::milliseconds;

class Time {
public:
  Time()
      : start_time(std::chrono::time_point<
                   std::chrono::high_resolution_clock>::min()) {}

  void reset_timer() { start_time = std::chrono::high_resolution_clock::now(); }

  template <typename DurationType> long long get_elapsed_time() {
    if (start_time ==
        std::chrono::time_point<std::chrono::high_resolution_clock>::min()) {
      throw std::runtime_error("Timer has not been reset.");
    }
    auto now = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<DurationType>(now - start_time).count();
  }

private:
  std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
};

class CacheTester {
public:
  void run_single_reads(size_t size) {
    const size_t array_size = size;
    std::vector<int> large_array(array_size);

    // Initialize the large_array with some values for testing
    for (size_t i = 0; i < array_size; ++i) {
      large_array[i] = static_cast<int>(i);
    }

    std::cout << "x,y\n";

    Time t;
    t.reset_timer();

    // Read values and print the time taken for each read in nanoseconds
    for (size_t i = 0; i < array_size; ++i) {

      std::cout << i << ",";

      t.reset_timer(); // Reset timer for each read
      volatile int temp = large_array[i];
      long long elapsed_time =
          t.get_elapsed_time<std::chrono::nanoseconds>(); // Get elapsed time
                                                          // for the read

      std::cout << elapsed_time; // Print elapsed time for the read

      std::cout << std::endl;
    }
    // std::cout << std::endl; // New line after printing all times

    // std::cout << "Total elapsed time for all reads: "
    //           << t.get_elapsed_time<std::chrono::nanoseconds>() << " ns"
    //           << std::endl;
  }

  void run_batched_reads(size_t array_size, size_t batch_size,
                         size_t iterations) {
    std::vector<int> large_array(array_size);

    // Initialize the array
    for (size_t i = 0; i < array_size; ++i) {
      large_array[i] = static_cast<int>(i);
    }

    Time t;

    std::cout << "batch,time\n";
    size_t count = 0;

    for (size_t iter = 0; iter < iterations; ++iter) {

      volatile int sum = 0;

      // Batched read the size of the L1 cache
      // print each batch
      for (size_t i = 0; i < array_size; i += batch_size) {
        t.reset_timer();
        size_t batch_end = std::min(i + batch_size, array_size);
        for (size_t j = i; j < batch_end; ++j) {
          large_array[j] = large_array[j] * 2;
        }
        long long elapsed_time = t.get_elapsed_time<std::chrono::nanoseconds>();
        std::cout << count++ << "," << elapsed_time << "\n";
      }
    }
  }
};

int main(int argc, char *argv[]) {
  // Check if the correct number of arguments is provided
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <size>" << std::endl;
    return 1; // Exit with an error code
  }

  // Convert the command line argument to an integer
  size_t size = std::stoul(argv[1]); // Use stoul to convert string to size_t

  CacheTester tester;

  tester.run_batched_reads(size, 32000, 3);

  std::cout << std::endl;
}

/*

10
100
1000


10000


*/