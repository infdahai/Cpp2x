#include <iostream>
#include <string_view>

enum class Color { red, green, blue };

std::string_view toString(Color col) {
  switch (col) {
    using enum Color;
    case red:
      return "red";
    case green:
      return "green";
    case blue:
      return "blue";
  }
  return "unknown";
}

struct BitField20 {
  int i : 3 = 1;
  int j : 4 = 1;
  int k : 5 = 1;
  int l : 6 = 1;
  int m : 7 = 1;
  int n : 8 = 1;
};