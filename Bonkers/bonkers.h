//here begins bonkers.h
//contains global variables, structure definitions, and function definitions

#include <iostream>
#include <cmath>

//Global variables
const double dt = 0.01; //time step
const int N = 1000; //number of particles


//Global constants
const double pi = 4*atan(1); //pi

//Structures
struct Ball { //stores information about a ball
	double x[2]; //x and y coordinate
	double v[2]; //velocity in x and y directions
	double im; //1 / mass of particles
	double a; //radius
};

struct Wall { //stores information about the walls of the container
	double l; //position of left wall
	double r; //position of right wall 
	double t; //position of top wall
	double b; //position of bottom wall
	double v; //velocity of right wall
	double a; //minimum displacement of right wall
};

//Functions
void progress(double &x, double v); //moves a ball to the next position
void collision(double &v1, double &v2, double im1, double im2); //calculates the new velocities of colliding particles, assuming elastic collision
double drand(double min, double max); //calculates a random double
void compress(double &r, double &v, double t, double a); //moves the wall to the next position
void behindWall(double &x, double &y, double v1, double v2, double r, double a); //places any particles colliding with the right wall behind it, to prevent particles escaping the box
double energy(double v1, double v2, double m); //calculates the energy of a particle