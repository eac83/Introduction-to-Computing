//Here begins ene.cc
//calculates energy of planet

#include "planets.h"
#include <cmath>
using namespace std;
float ene(float v0, float v1, float m, float r) {
	float k = (1/2)*m*(pow(v0, 2) + pow(v1, 2));
	float u = -G*M*m/r;
	return k + u;
} 