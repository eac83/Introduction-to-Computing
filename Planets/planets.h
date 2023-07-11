//Here begins planets.h
/*Contains the declarations of all functions used in the program, global constants used by all files, and the Planet structure*/
#include <cmath>

//functions used
float calcR(float x0, float x1);
float force(float x, float m, float r);
void pos(float &x, float v, float dt);
void tim(float &t, float dt);
void vel(float &v, float f, float m, float dt);
float ene(float v0, float v1, float m, float r);
float ang(float m, float x0, float x1, float v0, float v1);

//constants
const float G = 6.67408 * pow(10, -11); //Gravitational constant
const float M = 1.989 * pow(10, 30); //Solar mass
const float mE = 5.9722 * pow(10, 24); //Earth mass
const float AU = 1.496 * pow(10, 11); //Astronomical unit
const float dt = 24*60*60*7; //Time step of one week

//structures
struct Planet //stores information about the planet
{
	float m; //planet mass
	float x[2]; //planet position
	float v[2]; //planet velocity
	float f[2]; //gravitational force on planet
};
