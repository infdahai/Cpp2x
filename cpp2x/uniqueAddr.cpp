#include <iostream>

struct Empty {};

struct NoUniqueAddr {
  int d{};
  [[no_unique_address]] Empty e{};
};

// static_assert(sizeof(int) == sizeof(NoUniqueAddress));