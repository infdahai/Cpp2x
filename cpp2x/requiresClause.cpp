#include <iostream>

template <unsigned int i>
  requires(i <= 20)
int sum(int j) {
  return i + j;
}

