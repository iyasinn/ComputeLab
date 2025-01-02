#include <cstddef>
#include <memory>

template <typename Type, typename Deleter = std::default_delete<Type>>
class custom_unique_ptr {
public:
  custom_unique_ptr() : data(nullptr), deleter(Deleter()) {}
  custom_unique_ptr(std::nullptr_t) : data(nullptr), deleter(Deleter()) {}
  custom_unique_ptr(Type *pointer) : data(pointer), deleter(Deleter()) {}

  Type *get() { return data; }

  Type *release() {
    Type *temp = data;
    data = nullptr;
    return temp;
  }

  void reset(Type *ptr) {
    if (data) {
      deleter(data);
    }
    data = ptr;
  }

  Deleter &get_deleter() const { return deleter; }

  ~custom_unique_ptr() {
    if (data) {
      deleter(data);
    }
  }

private:
  Type *data;
  Deleter deleter;
};

template <typename Type> custom_unique_ptr<Type> make_unique(Type data);

/*


get deleter
get
release
reset
swap

constructors:

takes nullptr
pointers
or other unique pointres


*/