#pragma once
#include <iostream>

struct Implicit {
  template <typename T>
  Implicit(T t) {
    std::cout << t << "\n";
  }
};

struct Explicit {
  template <typename T>
  explicit Explicit(T t) {
    std::cout << t << "\n";
  }
};

// Explicit exp1 = "implicit"; // Error
Explicit exp2{"explicit"};