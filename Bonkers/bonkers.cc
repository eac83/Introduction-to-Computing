//here begins bonkers.cc
//contains main function of Bonkers
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

#include "bonkers.h"

//open files
ofstream bout("balls.txt"); //stores positions of each ball at each time interval
ofstream wout("wall.txt"); //stores the position of the right wall at each time interval
ofstream tout("energy.txt"); //stores the internal energy of the system against the volume of the box
double T = 0; //total internal energy of system
double u = 0; //velocity of stationary walls
//main function
int main() {
	//create the walls of the container
	Wall wall = {-10, 5, 10, -10, 5, 5};
	
	//create N particles
	Ball *balls;
	
	balls = new Ball[N];
	
	for(int n = 0; n < N; n++) {
		//put the particles at a random position with random velocities
		balls[n] = {{drand(wall.l+1.0, wall.r-1.0), drand(-9, 9)}, {drand(-5, 5), drand(-5, 5)}, 1.0, 0.1};
	}
	
	for(double t = 0; t < 20; t = t + dt) {
		T = 0;
		for(int i = 0; i < N; i++) {
			
			//move the balls to new positions
			progress(balls[i].x[0], balls[i].v[0]);
			progress(balls[i].x[1], balls[i].v[1]);
			
			//check if ball collides with a wall
			if((balls[i].x[0] - balls[i].a) <= wall.l ) {
				collision(balls[i].v[0], u, balls[i].im, 0);
			}
			
			if((balls[i].x[0] + balls[i].a >= wall.r)){
				behindWall(balls[i].x[0], balls[i].x[1], balls[i].v[0], balls[i].v[1], wall.r, balls[i].a);
				collision(balls[i].v[0], wall.v, balls[i].im, 0);
			}
			
			if(balls[i].x[1] - balls[i].a <= wall.b or balls[i].x[1] + balls[i].a >= wall.t) {
				collision(balls[i].v[1], u, balls[i].im, 0);
			}
			
			//check if ball collides with another ball
			for(int x = 0; x < i; x++) {
				if(abs(balls[i].x[0] - balls[x].x[0]) <= balls[i].a + balls[x].a and abs(balls[i].x[1] - balls[x].x[1]) <= balls[i].a + balls[x].a and i != x) {
					collision(balls[x].v[0], balls[i].v[0], balls[x].im, balls[i].im);
					collision(balls[x].v[1], balls[i].v[1], balls[x].im, balls[i].im);
				}
			}
			
			//calculate the energy of the system
			T = T + energy(balls[i].v[0], balls[i].v[1], balls[i].im);
			
			//output particle positions
			bout << balls[i].x[0] << "	" << balls[i].x[1] << "	" << balls[i].a << "	";
		}
		
		//output energy of system
		tout << 20*(wall.r+10) << "	" << T << "	" << pow((20*(wall.r+10)), -1)  << endl;
		
		//output wall position
		wout << wall.r << "	" << -10 << "	" << t << endl << wall.r << "	" << 10 << endl;
		bout << endl;
		
		//move wall
		compress(wall.r, wall.v, t, wall.a);
	}
	
	//data management
	bout.close();
	wout.close();
	tout.close();
	delete [] balls;
}


