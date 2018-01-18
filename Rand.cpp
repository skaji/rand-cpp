#include "Rand.hpp"

#include <time.h>

pid_t Rand::pid_(getpid());
boost::random::mt19937 Rand::engine_(time(NULL) ^ pid_);
boost::random::uniform_int_distribution<> Rand::dist_(0, 9999);

Rand::Rand() {
  pid_t pid = getpid();
  if (pid_ != pid) {
    pid_ = pid;
    engine_.seed(time(NULL) ^ pid_);
  }
}
Rand::~Rand() {}

int Rand::call() const {
  return dist_(engine_);
}
