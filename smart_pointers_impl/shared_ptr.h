#include <cstddef>
#include <memory>

template <typename Type, typename Deleter = std::default_delete<Type>>
class custom_unique_ptr {
public:
  custom_unique_ptr() : data(nullptr), deleter(Deleter()) {}
  custom_unique_ptr(std::nullptr_t) : data(nullptr), deleter(Deleter()) {}
  custom_unique_ptr(Type *pointer, Deleter deleter_in)
      : data(pointer), deleter(deleter_in) {}

  // delete the reference operator
  custom_unique_ptr(custom_unique_ptr &other) = delete;

  // delete the copy assignment operator
  custom_unique_ptr operator=(custom_unique_ptr rhs) = delete;

private:
  Type *data;
  Deleter deleter;
};
