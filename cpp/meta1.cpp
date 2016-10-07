#include <iostream>

template <int N, int D>
struct Fraction {
  // check for denominator to be equal to zero
  static_assert(D != 0, "Denominator must be a non-zero value");

  static constexpr auto Num = N;
  static constexpr auto Den = D;
};

template <int N, typename F>
struct ScalarMul {
  using result = Fraction<F::Num * N, F::Den * N>;
};

template <int A, int B>
struct GCD {
  static constexpr auto value = GCD<B, A % B>::value;
};

template <int A>
struct GCD<A, 0> {
  static constexpr auto value = A;
};

template <typename F>
struct SimplifyRational {
  using gcd = GCD<F::Num, F::Den>;
  using result = Fraction<F::Num / gcd::value, F::Den / gcd::value>;
};

int main() {
  using sm = ScalarMul<5, Fraction<5, 10>>::result;
  std::cout << sm::Num << '/' << sm::Den << std::endl;
  using simple = SimplifyRational<sm>::result;
  std::cout << simple::Num << '/' << simple::Den << std::endl;

  return 0;
}
