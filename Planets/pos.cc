//Here begins pos.cc
//calculates the position component of a planet

#include "planets.h"
using namespace std;

void pos(float &x, float v, float dt) {
	x = x + dt*v;
}