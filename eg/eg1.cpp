#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Rand.hpp"

using namespace std;

class RandHolder {
 public:
  RandHolder() : rand_(NULL) {
    rand_ = new Rand();
  }
  ~RandHolder() {
    delete rand_;
    rand_ = NULL;
  }
  RandHolder(const RandHolder& copy) : rand_(NULL) {
    rand_ = new Rand();
    *rand_ = *(copy.rand_);
  }
  RandHolder& operator=(const RandHolder& other) {
    if (this != &other) {
      *rand_ = *(other.rand_);
    }
    return *this;
  }
  int call() const {
    return rand_->call();
  }
 private:
  Rand* rand_;
};

int main(void) {
  RandHolder base;
  {
    RandHolder r;
    cout << r.call() << "\n";
    cout << r.call() << "\n";
    cout << r.call() << "\n";
    cout << r.call() << "\n";
    base = r;
  }
  cout << base.call() << "\n";
  cout << base.call() << "\n";
  cout << base.call() << "\n";
  cout << base.call() << "\n";

  RandHolder foo(base);
  cout << foo.call() << "\n";

  return 0;
}
