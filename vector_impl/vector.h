#include <cstddef>
template <typename T> class Vector {

public:
  Vector() {}

private:
  static const size_t INITIAL_SIZE = 8;

  T *_data;
  size_t _capacity;
  size_t _size;
};

template <typename T> class FastVector {

public:
  FastVector() {}

private:
  static const size_t INITIAL_SIZE = 8;

  size_t get_size() {
    return metadata & 0xFFFF; // Extract lower 16 bits
  }

  size_t get_capacity() {
    return (metadata >> 16) & 0xFFFF; // Extract upper 16 bits
  }

  T *_data;
  size_t metadata;
};