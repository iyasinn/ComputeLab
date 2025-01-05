#include "unique_ptr.h"
#include <iostream>

// Hello

int main() {

  custom_unique_ptr<int> ptr(new int(42));
  std::cout << "Value: " << *ptr.get() << std::endl;

  int *raw_ptr = ptr.release();
  std::cout << "Value after release: " << *raw_ptr << std::endl;
  std::cout << "Is nullptr? " << (ptr.get() == nullptr) << std::endl;
  delete raw_ptr;

  custom_unique_ptr<int> ptr2(new int(100));
  std::cout << "Value: " << *ptr2.get() << std::endl;

  ptr2.reset(new int(200));
  std::cout << "Value after reset: " << *ptr2.get() << std::endl;

  return 0;
}