#include <iostream>
#include <map>
#include <vector>

template <typename T>
struct has_size_method {
 private:
  template <typename U, typename = decltype(U().size())>
  static int detect(U &&);
  // type T doesn't have size() method
  static void detect(...);

 public:
  static constexpr bool value =
      std::is_same<int, decltype(detect(std::declval<T>()))>::value;
};

template <typename T>
struct has_mapped_type {
 private:
  template <typename U, typename = typename U::mapped_type>
  static int detect(U &&);
  // type T doesn't have ::mapped_type field
  static void detect(...);

 public:
  static constexpr bool value =
      std::is_same<int, decltype(detect(std::declval<T>()))>::value;
};

int main() {
  std::cout << "size() method test:" << std::endl;
  std::cout << "vector " << has_size_method<std::vector<int>>::value
            << std::endl;
  std::cout << "int " << has_size_method<int>::value << std::endl;
  std::cout << "map " << has_size_method<std::map<int, int>>::value
            << std::endl;
  std::cout << "has ::mapped_type field" << std::endl;
  std::cout << "vector " << has_mapped_type<std::vector<int>>::value
            << std::endl;
  std::cout << "int " << has_mapped_type<int>::value << std::endl;
  std::cout << "map " << has_mapped_type<std::map<int, int>>::value
            << std::endl;

  return 0;
}
