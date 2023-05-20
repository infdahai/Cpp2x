#include <concepts>
#include <iostream>

struct NotCopyable {
  NotCopyable() = default;
  NotCopyable(const NotCopyable&) = delete;
};

template <typename T>
struct MyVector {
  void push_back(const T&)
    requires std::copyable<T>
  {}
};
