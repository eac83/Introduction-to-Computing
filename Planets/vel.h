#include "planets.h"
using namespace std;

void vel(float &v, float dt, float f, float m) {
	v = v + dt * f / m;
}