#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

template <typename T>
struct has_size_method {
  template <typename U>
  using detect_type =
  typename std::enable_if<true, decltype(std::declval<U>().size())>::type;

  template <typename U, typename = detect_type<U>>
  static int detect(U &&);

  // type T doesn't have size() method
  static void detect(...);

  static constexpr bool value =
      std::is_same<int, decltype(detect(std::declval<T>()))>::value;
};

template <typename T>
struct has_mapped_type {
  template <typename U>
  using detect_type =
  typename std::enable_if<true, typename U::mapped_type>::type;

  template <typename U, typename = detect_type<U>>
  static int detect(U &&);

  // type T doesn't have ::mapped_type field
  static void detect(...);

  static constexpr bool value =
      std::is_same<int, decltype(detect(std::declval<T>()))>::value;
};

int main() {
  std::cout << "size() method test:" << std::endl;
  std::cout << "vector " << has_size_method<std::vector < int>>
  ::value
      << std::endl;
  std::cout << "int " << has_size_method<int>::value << std::endl;
  std::cout << "map " << has_size_method<std::map < int, int>>
  ::value
      << std::endl;
  std::cout << "has ::mapped_type field" << std::endl;
  std::cout << "vector " << has_mapped_type<std::vector < int>>
  ::value
      << std::endl;
  std::cout << "int " << has_mapped_type<int>::value << std::endl;
  std::cout << "map " << has_mapped_type<std::map < int, int>>
  ::value
      << std::endl;

  return 0;
}
