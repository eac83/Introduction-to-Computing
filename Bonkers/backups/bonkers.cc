#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double t = 0;
double dt = 0.01;
double u = 0;
int N = 10000;
double pi = 4*atan(1);
double T = 0;

struct Ball {
	double x[2];
	double v[2];
	double im;
	double a;
};

struct Wall {
	double l;
	double r;
	double t;
	double b;
	double v;
	double a;
};

void timeStep(double &t);
void progress(double &x, double v);
void collision(double &v1, double &v2, double im1, double im2);
double drand(double min, double max);
void compress(double &r, double &v, double t, double a);
void behindWall(double &x, double &y, double v1, double v2, double r, double a);
double energy(double v1, double v2, double m);

ofstream bout("balls.txt");
ofstream wout("wall.txt");
ofstream tout("energy.txt");

int main() {
	Wall wall = {-10, 5, 10, -10, 5, 5};
	Ball balls[N];
	
	for(int n = 0; n < N; n++) {
		balls[n] = {{drand(wall.l+1.0, wall.r-1.0), drand(-9, 9)}, {drand(-5, 5), drand(-5, 5)}, 1.0, 0.1};
	}
	
	for(double t = 0; t < 20; t = t + dt) {
		T = 0;
		for(int i = 0; i < N; i++) {
			
			
			progress(balls[i].x[0], balls[i].v[0]);
			progress(balls[i].x[1], balls[i].v[1]);
			
			if((balls[i].x[0] - balls[i].a) <= wall.l ) {
				collision(balls[i].v[0], u, balls[i].im, 0);
			}
			
			if((balls[i].x[0] + balls[i].a >= wall.r)){
				behindWall(balls[i].x[0], balls[i].x[1], balls[i].v[0], balls[i].v[1], wall.r, balls[i].a);
				collision(balls[i].v[0], wall.v, balls[i].im, 0);
				//balls[i].v[0] = balls[i].v[0] + wall.v;
			}
			
			if(balls[i].x[1] - balls[i].a <= wall.b or balls[i].x[1] + balls[i].a >= wall.t) {
				collision(balls[i].v[1], u, balls[i].im, 0);
			}
			
			for(int x = 0; x < i; x++) {
				if(abs(balls[i].x[0] - balls[x].x[0]) <= balls[i].a + balls[x].a and abs(balls[i].x[1] - balls[x].x[1]) <= balls[i].a + balls[x].a and i != x) {
					collision(balls[x].v[0], balls[i].v[0], balls[x].im, balls[i].im);
					collision(balls[x].v[1], balls[i].v[1], balls[x].im, balls[i].im);
				}
			}
			T = T + energy(balls[i].v[0], balls[i].v[1], balls[i].im);
			//cout << "vx " << pow(balls[i].v[0], 2) << "	vy " << pow(balls[i].v[1],2) << "	m " << 1/balls[i].im << endl;
			bout << balls[i].x[0] << "	" << balls[i].x[1] << "	" << balls[i].a << "	";
		}
		
		tout << 20*(wall.r+10) << "	" << T << "	" << 1/(20*(wall.r+10)) << endl;
		wout << wall.r << "	" << -10 << "	" << t << endl << wall.r << "	" << 10 << endl;
		bout << endl;
		compress(wall.r, wall.v, t, wall.a);
	}
	
	bout.close();
	wout.close();
	tout.close();
}

void timeStep(double &t) {
	t = t + dt;
}

void progress(double &x, double v) {
	x = x + dt*v;
}

void collision(double &v1, double &v2, double im1, double im2) {
	double u1 = v1;
	double u2 = v2;
	v1 = ((im2-im1)*u1 + 2*im1*u2) / (im2+im1);
	v2 = (2*im2*u1 + (im1-im2)*u2) / (im2+im1);
}

double drand(double min, double max) {
	double f = (double)rand() / RAND_MAX;
	return min + f * (max-min);
}

void compress(double &r, double &v, double t, double a) {
	if (r <= -a or r >= 10) {
		v = -v;
	}
	r = r + v*dt;
	
}

void behindWall(double &x, double &y, double v1, double v2, double r, double a) {
	y = y - (x-r+a)*v2/v1;
	x = r - a;
}

double energy(double v1, double v2, double m) {
	double e = (0.5*(pow(v1,2)+pow(v2,2))/m);
	//cout << e << endl;
	return e;
}
