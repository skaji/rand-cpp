#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "Rand.hpp"

using namespace std;

int main(void) {
  Rand rand;

  map<int, int> times;
  for (int i = 0; i < 10000000; ++i) {
    int j = rand.call();
    if (times.find(j) == times.end()) {
      times[j] = 1;
    } else {
      times[j]++;
    }
  }
  for (map<int, int>::const_iterator it = times.begin(); it != times.end(); ++it) {
    cout << it->first << " " << it->second << "\n";
  }

  return 0;
}
