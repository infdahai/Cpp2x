#include <iostream>
#include <string>
#include <vector>

int a() {
  for (auto vec = std::vector<int>{1, 2, 3}; auto v : vec) {
    std::cout << v << " ";
  }
  using namespace std::string_literals;
  for (auto str = "Hello World"s; auto c : str) {
    std::cout << c << " ";
  }
}