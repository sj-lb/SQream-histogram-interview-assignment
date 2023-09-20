CC = g++
CFLAGS = -std=c++11 -pedantic -Wall -Wextra -g -I .
LDFLAGS= -pthread

hist: dict_hist.cpp dict_hist_tostr.cpp dict_hist_test.cpp dict_hist.hpp
	$(CC) -o $@ $(CFLAGS) $^

mt_hist: mt_dict_hist.cpp dict_hist_tostr.cpp dict_hist_test.cpp dict_hist.hpp
	$(CC) -o $@ $(CFLAGS) $^ $(LDFLAGS)