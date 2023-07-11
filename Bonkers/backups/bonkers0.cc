#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double dt = 0.1;
double u = 0;
int N = 5;

struct Ball {
	double x;
	double v;
	double im;
	double a;
};

void progress(double &x, double v);
void collision(double &v1, double &v2, double im1, double im2);

ofstream bout("balls.txt");

int main() {
	Ball balls[N] = {{-5.0, 2.0, 1.0, 1.0}, {-2.5, -2.0, 1.0, 1.0}, {0, 2.0, 1.0, 1.0}, {2.5, -2.0, 1.0, 1.0}, {5.0, 2.0, 1.0, 1.0}};
	for(double t = 0; t < 10; t = t + dt) {
		
		for(int i = 0; i < N; i++) {
			progress(balls[i].x, balls[i].v);
			
			if(abs(balls[i].x) >= 10 - balls[i].a) {
				collision(balls[i].v, u, balls[i].im, 0);
			}
			
			for(int x = 0; x < i; x++) {
				if(abs(balls[i].x - balls[x].x) <= balls[i].a + balls[x].a and i != x) {
					collision(balls[x].v, balls[i].v, balls[x].im, balls[i].im);
				}
			}
			
			bout << balls[i].x << "	" << 0 << "	" << balls[i].a << "	";
		}
		bout << endl;
	}
	
	bout.close();
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
