#include "Vector.h"
#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Create different vector types
  std::vector<int> intVec;
  std::vector<bool> boolVec;
  std::vector<double> doubleVec;
  std::vector<char> charVec;
  Vector<int> myIntVec;

  // Print sizes of different vector types
  std::cout << "Size of vector<int>: " << sizeof(intVec) << " bytes\n";
  std::cout << "Size of vector<bool>: " << sizeof(boolVec) << " bytes\n";
  std::cout << "Size of vector<double>: " << sizeof(doubleVec) << " bytes\n";
  std::cout << "Size of vector<char>: " << sizeof(charVec) << " bytes\n";
  std::cout << "Size of Vector<int>: " << sizeof(myIntVec) << " bytes\n";

  return 0;
}