#ifndef RAND_HPP_
#define RAND_HPP_

#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/random_device.hpp>

class Rand {
 public:
  Rand();
  ~Rand();
  int call() const;
 private:
  static pid_t pid_;
  static boost::random::mt19937 engine_;
  static boost::random::uniform_int_distribution<> dist_;
};

#endif
