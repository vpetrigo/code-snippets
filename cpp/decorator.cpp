#include <iostream>
#include <memory>

class Interface {
 public:
  virtual ~Interface() = default;
  virtual void do_smth() = 0;
};

class SomeBase : public Interface {
 public:
  ~SomeBase() override = default;

  void do_smth() override { std::cout << "SomeBase do_smth()" << std::endl; }
};

class Decorator : public Interface {
 public:
  Decorator(std::unique_ptr<Interface> p) : wrappee{std::move(p)} {}

  ~Decorator() = default;

  void do_smth() override {
    std::cout << "Start Deco do_smth()" << std::endl;
    wrappee->do_smth();
    std::cout << "End Deco do_smth()" << std::endl;
  }

 private:
  std::unique_ptr<Interface> wrappee;
};

class DecoratorX : public Decorator {
 public:
  DecoratorX(std::unique_ptr<Interface> p) : Decorator(std::move(p)) {}

  ~DecoratorX() = default;

  void do_smth() override {
    std::cout << "Start DecoX do_smth()" << std::endl;
    Decorator::do_smth();
    std::cout << "End DecoX do_smth()" << std::endl;
  }
};

int main() {
  SomeBase sb;

  sb.do_smth();

  std::unique_ptr<Interface> d =
      std::make_unique<Decorator>(std::make_unique<SomeBase>());
  std::unique_ptr<Interface> dx =
      std::make_unique<DecoratorX>(std::make_unique<SomeBase>());

  d->do_smth();
  dx->do_smth();

  return 0;
}
