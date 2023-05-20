#include <concepts>
#include <iostream>
#include <vector>

template <typename T>
concept Equal = requires(T a, T b) {
  { a == b } -> std::convertible_to<bool>;
  { a != b } -> std::convertible_to<bool>;
};

bool areEqual(Equal auto a, Equal auto b) { return a == b; }

struct WithoutEqual {
  bool operator==(const WithoutEqual& other) = delete;
};

struct WithoutUnEqual {
  bool operator!=(const WithoutUnEqual& other) = delete;
};

template <typename T>
concept Ording = Equal<T> && requires(T a, T b) {
  { a <= b } -> std::convertible_to<bool>;
  { a < b } -> std::convertible_to<bool>;
  { a >= b } -> std::convertible_to<bool>;
  { a > b } -> std::convertible_to<bool>;
};

template <Ording T>
T getSmaller(const T& a, const T& b) {
  return (a < b) ? a : b;
}
