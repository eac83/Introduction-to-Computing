//Herebegins planets.cc
#include <iostream>
#include <cmath>
#include <fstream>

#include "planets.h"

using namespace std;

//variables

float t = 0;

//arrays
float r[5] = {0, 0, 0, 0, 0};

//files
ofstream euler("euler.txt");
ofstream eeng("eeng.txt");
ofstream eang("eang.txt");
ofstream lf("leapfrog.txt");
ofstream leng("leng.txt");
ofstream lang("lang.txt");

//main
int main() {
	//create planets
	Planet planets[5] = {{mE, {2*AU, AU}, {0, -10*1000}, {0,0}},
	{mE, {1.8*AU, AU}, {0, -10*1000}, {0,0}},
	{mE, {1.6*AU, AU}, {0, -10*1000}, {0,0}},
	{mE, {1.4*AU, AU}, {0, -10*1000}, {0,0}},
	{mE, {1.2*AU, AU}, {0, -10*1000}, {0,0}}};
	
	//eulers
	for (int c = 0; c < 200; c++) {
		for (int p = 0; p < 5; p++) {
			
			r[p] = calcR(planets[p].x[0], planets[p].x[1]);
		
			for (int i = 0; i < 2; i++) {
				planets[p].f[i] = force(planets[p].x[i], planets[p].m, r[p]);
				pos(planets[p].x[i], planets[p].v[i], dt);
				vel(planets[p].v[i], planets[p].f[i], planets[p].m, dt);
			}
			euler << planets[p].x[0] << "	" << planets[p].x[1] << "	";
			eeng << t/(24*60*60*7) << "	" << ene(planets[p].v[0], planets[p].v[1], planets[p].m, r[p]) << "	";
			eang << t/(24*60*60*7) << "	" << ang(planets[p].m, planets[p].x[0]/1000, planets[p].x[1]/1000, planets[p].v[0]/1000, planets[p].v[1]/1000) << "	";
		}
		tim(t, dt);
		euler << endl;
		eeng << endl;
		eang << endl;
	}
	
	Planet planets2[5] = {{mE, {2*AU, AU}, {0, -10*1000}, {0,0}},
	{mE, {1.8*AU, AU}, {0, -10*1000}, {0,0}},
	{mE, {1.6*AU, AU}, {0, -10*1000}, {0,0}},
	{mE, {1.4*AU, AU}, {0, -10*1000}, {0,0}},
	{mE, {1.2*AU, AU}, {0, -10*1000}, {0,0}}};
	
	//leapfrog
	for (int c = 0; c < 200; c++) {
		for (int p = 0; p < 5; p++) {
			
			r[p] = calcR(planets2[p].x[0], planets[p].x[1]);
			
			for (int i = 0; i < 2; i++) {
				pos(planets2[p].x[i], planets2[p].v[i], dt/2);
			}

		}
		tim(t, dt/2);
		for (int p = 0; p < 5; p++) {
			
			r[p] = calcR(planets2[p].x[0], planets[p].x[1]);
			
			for (int i = 0; i < 2; i++) {
				planets2[p].f[i] = force(planets2[p].x[i], planets2[p].m, r[p]);
				vel(planets2[p].v[i], planets2[p].f[i], planets2[p].m, dt/2);
				pos(planets2[p].x[i], planets2[p].v[i], dt/2);
			}
			lf << planets2[p].x[0] << "	" << planets2[p].x[1] << "	";
			leng << t/(24*60*60*7) << "	" << ene(planets2[p].v[0], planets2[p].v[1], planets2[p].m, r[p]) << "	";
			lang << t/(24*60*60*7) << "	" << ang(planets2[p].m, planets2[p].x[0]/1000, planets2[p].x[1]/1000, planets2[p].v[0]/1000, planets2[p].v[1]/1000) << "	";
		}
		tim(t, dt);
		lf << endl;
		leng << endl;
		lang << endl;
	}
	
	//destroy data
	
	euler.close();
	eeng.close();
	eang.close();
	lf.close();
	leng.close();
	lang.close();
	
	return 0;
}
