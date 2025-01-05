#include <cstddef>
#include <memory>

template <typename Type, typename Deleter = std::default_delete<Type>>
class custom_shared_ptr {
public:
  custom_shared_ptr() : data(nullptr), deleter(Deleter()) {}
  custom_shared_ptr(std::nullptr_t) : data(nullptr), deleter(Deleter()) {}
  custom_shared_ptr(Type *pointer, Deleter deleter_in)
      : data(pointer), deleter(deleter_in) {}

  // delete the reference operator
  custom_shared_ptr(custom_shared_ptr &other) = delete;

  // delete the copy assignment operator
  custom_shared_ptr operator=(custom_shared_ptr rhs) = delete;

private:
  Type *data;
  Deleter deleter;
};
