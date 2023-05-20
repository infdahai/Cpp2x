
#include <atomic>
#include <bitset>
#include <compare>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <string>
#include <thread>
#include <vector>

#include "construct.h"

struct MyInt {
  int value;
  MyInt(int value) : value{value} {}
  auto operator<=>(const MyInt&) const = default;
};

class Point3D {
 public:
  int x;
  int y;
  int z;
};

consteval int sqr(int n) { return n * n; }

template <typename T>
concept Addable = requires(T a, T b) { a + b; };

template <Addable T>
T add2(T a, T b) {
  return a + b;
}



int main() {
  std::vector<int> ints{0, 1, 2, 3, 4, 5};
  auto even = [](int i) { return i % 2 == 0; };
  auto square = [](int i) { return i * i; };
  auto foo = []<typename T>(std::vector<T> const& vec) {};

  Point3D point3D{.x = 1, .y = 2, .z = 2};

  // for (int i :
  //      ints | std::views::filter(even) | std::views::transform(square)) {
  //   std::cout << i << ' ';
  // }

  std::uint8_t num = 0b10110010;
  std::cout << std::has_single_bit(num) << '\n';           // false
  std::cout << std::bit_width(unsigned(5)) << '\n';        // 3
  std::cout << std::bitset<8>(std::rotl(num, 2)) << '\n';  // 11001010
  std::cout << std::bitset<8>(std::rotr(num, 2)) << '\n';  // 1010110

  struct Counter {
    int a, b;
  };
  Counter counter;
  std::atomic_ref<Counter> cnt(counter);

  std::cout << std::boolalpha;
  std::thread thr{[] { std::cout << "Joinable std::thread" << '\n'; }};
  std::cout << "thr.joinable(): " << thr.joinable() << '\n';

  std::cout << "three way<int>:" << std::three_way_comparable<int> << std::endl;
}