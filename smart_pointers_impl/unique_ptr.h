#include <cstddef>

template <typename Type> class unique_ptr {
public:
  unique_ptr() {}
  unique_ptr(std::nullptr_t) {}

private:
};

template <typename Type> unique_ptr<Type> make_unique(Type data);