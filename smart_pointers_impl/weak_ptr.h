// weak_ptr Overview:
// A weak_ptr is a smart pointer that provides a non-owning reference to an
// object managed by a shared_ptr. It is used to break circular references that
// can lead to memory leaks.

// Key Characteristics:
// 1. Non-Owning: Does not contribute to the reference count of the object.
// 2. Use with shared_ptr: Created from a shared_ptr, but does not manage the
// object's lifetime.
// 3. Checking Validity: Use expired() to check if the object is still valid.
// 4. Locking: Convert to a shared_ptr using lock() to safely access the object.

// Implementation Guide:
// - Include <memory> to use weak_ptr and shared_ptr.
// - Initialize a weak_ptr from a shared_ptr.
// - Use expired() to check if the object is still alive.
// - Convert to a shared_ptr using lock() to access the object.
// - Use weak_ptr to break cycles in data structures.
// - Thread Safety: weak_ptr is thread-safe for use across multiple threads.

// Example Usage:
// std::shared_ptr<MyClass> sp = std::make_shared<MyClass>();
// std::weak_ptr<MyClass> wp = sp;
// if (auto sp = wp.lock()) {
//     // Use sp safely
// } else {
//     // Object has been destroyed
// }
