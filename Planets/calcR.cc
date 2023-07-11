//Here begins calcR.cc
//calculates the distance from planet to sun

#include "planets.h"
#include <cmath>
using namespace std;

float calcR(float x0, float x1) {
	return sqrt(pow(x0, 2) + pow(x1, 2));
}