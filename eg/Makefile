all: eg1 eg2

eg1: eg1.o
	g++ -o $@ $< -L$(PWD)/.. -lrand -Wl,-rpath,$(PWD)/..

eg2: eg2.o
	g++ -o $@ $< -L$(PWD)/.. -lrand -Wl,-rpath,$(PWD)/.. -L$(PWD)/../../benchmark-cpp -lbenchmark -Wl,-rpath,$(PWD)/../../benchmark-cpp

%.o: %.cpp
	g++ -I/home/skaji/src/github.com/skaji/benchmark-cpp -I$(PWD)/.. -fPIC -Wall -Werror -Wextra -O0 -g -c -o $@ $<
