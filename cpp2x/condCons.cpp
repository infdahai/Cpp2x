#include <algorithm>
#include <iostream>
#include <type_traits>
#include <typeinfo>

struct Mybool {
  template <typename T>
  explicit(!std::is_same<T, bool>::value) Mybool(T t) {
    std::cout << typeid(t).name() << std::endl;
  }
};

void needBool(Mybool b) {}

struct ClassType {
  constexpr ClassType(int) {}
};

template <ClassType cl>
auto getClassType() {
  return cl;
}

template <double d>
auto getDouble() {
  return d;
}

template <int N>
class StringLiteral {
 public:
  constexpr StringLiteral(const char (&str)[N]) {
    std::copy(str, str + N, data);
  }
  char data[N];
};

template <StringLiteral str>
class ClassTemplate {};

template <StringLiteral str>
void FunctionTemplate() {
  std::cout << str.data << '\n';
}

// ClassTemplate<"string literal"> cls;
// FunctionTemplate<"string literal">();
