all:
	clang++-3.6 -std=c++11 test.cpp ../gtest/gtest-all.o -lpthread -o test.out
