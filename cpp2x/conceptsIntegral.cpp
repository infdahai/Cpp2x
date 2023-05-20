#include <concepts>
#include <iostream>

template <typename T>
concept Integral = std::is_integral<T>::value;

template <typename T>
concept Signed_integral = Integral<T> && std::is_signed_v<T>;

template <typename T>
concept Unsigned_integral = Integral<T> && !std::is_signed_v<T>;

template <typename T>
concept Floating_point = std::is_floating_point_v<T>;

Integral auto gcd1(Integral auto a, Integral auto b) {
  if (b == 0)
    return a;
  else
    return gcd1(b, a % b);
}

template <typename T>
  requires Integral<T>
T gcd(T a, T b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

template <Integral T>
auto gcd2(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
