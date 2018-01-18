all: eg1 eg2

eg1: eg1.o
	g++ -o $@ $< -L$(PWD)/.. -lrand -Wl,-rpath,$(PWD)/..

eg2: eg2.o
	g++ -o $@ $< -L$(PWD)/.. -lrand -Wl,-rpath,$(PWD)/..

%.o: %.cpp
	g++ -I$(PWD)/.. -fPIC -Wall -Werror -Wextra -O0 -g -c -o $@ $<
