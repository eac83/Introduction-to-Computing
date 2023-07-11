#include "planets.h"
#include <cmath>
using namespace std;
//here begins ang.cc
//calculates angular momentum of planet

float ang(float m, float x0, float x1, float v0, float v1) {
	return m*abs(x0*v1-v0*x1);
}