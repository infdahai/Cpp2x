#include <concepts>
#include <iostream>
#include <string>
#include <vector>

auto sumDec = [](auto fir, decltype(fir) sec) { return fir + sec; };
auto sumTem = []<typename T>(T fir, T sec) { return fir + sec; };

auto lambdaVectorIntegral = []<std::integral T>(const std::vector<T>& vec) {
  return vec.size();
};
