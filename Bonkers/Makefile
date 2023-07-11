#here begins Makefile
#creates the program bonkers.exe

CFLAGS = -g -Wall

LIBS = -l stdc++ -lm

CXX = g++

planets: bonkers.o functions.o
	$(CXX) $(CFLAGS) $(LIBS) bonkers.o functions.o -o bonkers

%.o: %.cc
	$(CXX) $(CFLAGS)	$< -c -o $@
	
%: %.cc Makefile
	$(CXX) $(CFLAGS) $(LIBS) $< -o $@