#include "Rand.hpp"

pid_t Rand::pid_(getpid());
boost::random::random_device Rand::seed_;
boost::random::mt19937 Rand::engine_(seed_());
boost::random::uniform_int_distribution<> Rand::dist_(0, 9999);

Rand::Rand() {}
Rand::~Rand() {}

int Rand::call() const {
  pid_t pid = getpid();
  if (pid_ != pid) {
    pid_ = pid;
    engine_.seed(seed_());
  }
  return dist_(engine_);
}
