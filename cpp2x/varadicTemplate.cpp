#include <concepts>
#include <iostream>

template <std::integral... Args>
bool all(Args... args) {
  return (... && args);
}

template <std::integral... Args>
bool any(Args... args) {
  return (... || args);
}

template <std::integral... Args>
bool none(Args... args) {
  return not(... || args);
}