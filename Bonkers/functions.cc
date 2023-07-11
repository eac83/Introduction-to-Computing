//here begins functions.cc
//contains the definitions of functions used in bonkers
#include "bonkers.h"
#include <iostream>
#include <cmath>

using namespace std;
//moves a ball to the next position
void progress(double &x, double v) {
	x = x + dt*v;
}

//calculates the new velocities of colliding particles, assuming elastic collision
void collision(double &v1, double &v2, double im1, double im2) {
	double u1 = v1;
	double u2 = v2;
	v1 = ((im2-im1)*u1 + 2*im1*u2) / (im2+im1);
	v2 = (2*im2*u1 + (im1-im2)*u2) / (im2+im1);
}

//calculates a random double
double drand(double min, double max) {
	double f = (double)rand() / RAND_MAX;
	return min + f * (max-min);
}

//moves the wall to the next position
void compress(double &r, double &v, double t, double a) {
	if (r <= -a or r >= 10) {
		v = -v;
	}
	r = r + v*dt;
	
}

//places any particles colliding with the right wall behind it, to prevent particles escaping the box
void behindWall(double &x, double &y, double v1, double v2, double r, double a) {
	y = y - (x-r+a)*v2/v1;
	x = r - a;
}

//calculates the energy of a particle
double energy(double v1, double v2, double m) {
	double e = (0.5*(pow(v1,2)+pow(v2,2))/m);
	return e;
}