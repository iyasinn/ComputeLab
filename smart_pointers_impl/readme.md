Smart pointers are extremely valuable abstractions in C++
They are RAII wrappers over your data that let you effectively manage your resources
I want my smart pointers to be compliant with the C++ standard

---

# High level Design Notes

Let's talk a little bit about what good design looks like for structures like this

## **The rule of 3:**

Consider a copy constructor, copy assignment operator, or destructor. This rule states that if a class requires any **one** of these three, then it likely requires **all** of them

Sturcture of each of these looks as the following:

- `~Class();`
- `Class(const Class& other);`
- `Class& operator=(const Class& other);`

Note: Class a = b. This invokes the copy constructor rathre than the copy assignment operator.
Finally, also note that copy assignment can do a shallow or deep copy. It depends on implementation.

<!-- Classes that manage non-copyable resources through copyable handles may have to declare copy assignment and copy constructor private and not provide their definitions(until C++11)define copy assignment and copy constructor as = delete(since C++11). This is another application of the rule of three: deleting one and leaving the other to be implicitly-defined typically incorrect. -->

## The rule of 5

This is a simple addon. When we provide move semantics, it turns out that in the presence of user defined (even with = default or = delete), if you want move semantics you need all 5 of these.
That is, you always need all 5 if you want move semantics

The extra operators are

- `Class(Class&& other) noexcept`;
- `ClassName& operator=(Classname&& other) noexcept`;

Note: `noexcept` is commonly used with move semantics becase it allows for optimizations. Generally we don't use it, but here we can ensure that there will be no errors with our move semantics

To call these constructors, we have to use the `std::move` function

---

Now we know how everything works. For the next steps, since we know each a unique patr and shared poointer need to implement these

# Unique Pointer

CPP Reference
https://en.cppreference.com/w/cpp/memory/unique_ptr

- Unique pointers allocate memory for you
- When deleted, they deallocate that memory for youu

Smart Pointer

Weak Pointer
