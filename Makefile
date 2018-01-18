all: librand.so
	cd eg && $(MAKE)

librand.so: Rand.o
	g++ -shared -o librand.so Rand.o -lboost_random

Rand.o: Rand.cpp
	g++ -fPIC -Wall -Wextra -Werror -O0 -g -c -o Rand.o Rand.cpp
