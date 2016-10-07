#include <iostream>
#include <set>

template <typename T, typename ... Args>
struct max_type_size;

template <typename T, typename U, typename ... Args>
struct max_type_size<T, U, Args...> {
  static constexpr std::size_t t_size = max_type_size<T, Args...>::size;
  static constexpr std::size_t u_size = max_type_size<U, Args...>::size;
  static constexpr std::size_t size = t_size > u_size ? t_size : u_size;
};

template <typename T>
struct max_type_size<T> {
  static constexpr std::size_t size = sizeof(T);
};

int main() {
  std::cout << max_type_size<int, std::string, double>::size << std::endl;

  return 0;
}


