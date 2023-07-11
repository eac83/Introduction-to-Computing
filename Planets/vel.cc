//Here begins vel.cc
//calculates velocity of planet

#include "planets.h"
using namespace std;

void vel(float &v, float f, float m, float dt) {
	v = v + dt * f / m;
}