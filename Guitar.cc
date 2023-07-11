#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//initialise global variables
double pi = 4*atan(1); //stores pi
double f = 262; //frequency of the wave
double v = 405; //velocity of the wave
double k = 2*pi*f/v; //wavenumber
double w = 2*pi*f; //angular frequency
double psi[5][100]; //stores amplitude of each point at time t=T (psi(x,T))
double *ptr; //points to values psi
int line = 1; //stores current line number in file
int stringNum = 0; //stores current string number

//open global files
ofstream output("guitar.txt"); //stores numerical data
ofstream graph("graph.gnu"); //stores instructions to plot each frame
ofstream guitar("guitar.gnu"); //stores instructions to initialise and run graph.gnu


//initialise functions
int waveEq(double T); //calculates psi(x,T) for all x

int main() {

	//main variables
	ptr = psi; //set ptr to point to psi
	double t = 0; //time
	double tStep = 0.005; //time difference between frames
	
	//repeat for each string
	for(stringNum; stringNum < 6; stringNum++) {
		//produce data for each frame
		while(t <= 1) {
			waveEq(t);
			ptr = psi + 100*stringNum; //resets psi
			t+=tStep; //increase time
			output << line << endl;
			line++;
		};
		ptr = psi + 100
	};
	
	//write gnuplot instructions
	graph << "set term png" << endl << "outfile = sprintf('gif/guitar%03.0f.png', t)" << endl << "set output outfile" << endl << "plot 'guitar.txt' every ::(606*t+1)::(606*t+100) u 2:3 w points, 'guitar.txt' every ::(606*t+101)::(606*t+200) u 2:3 w points," << endl << "t = t + 1" << endl << "if(t<=" << 1/tStep << "100) reread;";
	guitar << "t = 0" << endl << "system('mkdir gif')" << endl << "load 'graph.gnu'";
	
	
	//clean up memory
	output.close();
	graph.close();
	guitar.close();
	delete ptr;
	return 0;
}

//calculates psi(x,T) and stores values in guitar.txt
int waveEq(double T) {
	for(double x = 0; x < 100; x++) {
		*ptr = sin(k*x/100-w*T) + 2*stringNum;
		
		output << line << "     " << x/100 << "     " << *ptr << endl;
		line++;
		ptr = ptr + 1;
	};
	
	return 1;
}