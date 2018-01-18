#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Rand.hpp"
#include "benchmark.hpp"

using namespace std;

void new_run() {
  Rand rand;
  int i = rand.call();
  (void)i;
}
Rand shared;
void shared_run() {
  int i = shared.call();
  (void)i;
}

int main(void) {
  // benchmark::timethis(100000, new_run);
  benchmark::cmpthese(1000000,
                      "new", new_run,
                      "shared", shared_run);
  return 0;
}
