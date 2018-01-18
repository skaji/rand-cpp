#include "Rand.hpp"

#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/random_device.hpp>

Rand::Rand() {}
Rand::~Rand() {}

int Rand::call() const {
  static pid_t pid(getpid());
  static boost::random::random_device seed;
  static boost::random::mt19937 engine(seed());
  static boost::random::uniform_int_distribution<> dist(0, 9999);
  if (pid != getpid()) {
    pid = getpid();
    engine.seed(seed());
  }
  return dist(engine);
}
