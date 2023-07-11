//Here begins force.cc
//calculates the force component acting on the planet
#include "planets.h"
using namespace std;
#include <iostream>
float force(float x, float m, float r) {
	return -G*M*m*x/pow(r,3);
	cout << m << endl;
}