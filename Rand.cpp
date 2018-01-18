#include "Rand.hpp"

boost::random::random_device Rand::seed_;

Rand::Rand() : engine_(seed_()), dist_(0, 9999) {}
Rand::~Rand() {}

int Rand::call() const {
  return dist_(engine_);
}
