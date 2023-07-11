#Here begins Makefile

CFLAGS = -g -Wall

LIBS = -l stdc++ -lm

CXX = g++

planets: planets.o calcR.o force.o pos.o vel.o tim.o ene.o ang.o
	$(CXX) $(CFLAGS) $(LIBS) planets.o calcR.o force.o pos.o vel.o tim.o ene.o ang.o -o planets

%.o: %.cc
	$(CXX) $(CFLAGS)	$< -c -o $@
	
%: %.cc Makefile
	$(CXX) $(CFLAGS) $(LIBS) $< -o $@