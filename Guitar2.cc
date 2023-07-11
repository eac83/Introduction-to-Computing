#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

//initialise global variables
double pi = 4*atan(1); //stores pi
double v = 405; //velocity of the wave
double *ptr; //points to values psi
int line = 1; //stores current line number in file
double tStep = 0.01; //time difference between frames

//open global files
ofstream eFile("e.txt"); //stores numerical data
ofstream aFile("a.txt"); //stores numerical data
ofstream dFile("d.txt"); //stores numerical data
ofstream gFile("g.txt"); //stores numerical data
ofstream bFile("b.txt"); //stores numerical data
ofstream EFile("E2.txt"); //stores numerical data
ofstream graph("graph.gnu"); //stores instructions to plot each frame
ofstream guitar("guitar.gnu"); //stores instructions to initialise and run graph.gnu

//guitar string class
class wire {
	public:
		double f; //frequency of the wave
		double k = 2*pi*f/v; //wavenumber
		double w = 2*pi*f; //angular frequency
		double psi[100]; //stores amplitude of each point at time t=T (psi(x,T))
		int num;
		double *ptr; //points to values psi
		
		//constructor
		wire(double freq, int n) {
			f = freq;
			k = 2*pi*f/v; //wavenumber
			w = 2*pi*f; //angular frequency
			num = n;
			ptr = psi;
		}
		
		int waveEq(double T); //calculates psi(x,T) for all x
		int timeEq(); //calculates psi(x,t)
} ;

//objects
wire eStr(82, 0);
wire aStr(110, 1);
wire dStr(147 ,2);
wire gStr(196 ,3);
wire bStr(247 ,4);
wire EStr(330 ,5);

int main() {
	//create string objects
	eStr.timeEq();
	aStr.timeEq();
	dStr.timeEq();
	gStr.timeEq();
	bStr.timeEq();
	EStr.timeEq();
	
	//write gnuplot instructions
	graph << "set term png" << endl << "outfile = sprintf('gif/guitar%03.0f.png', t)" << endl << "set output outfile" << endl << "plot 'e.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'a.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'd.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'g.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'b.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points, 'E2.txt' every ::(100*t+1)::(100*t+100) u 3:4 w points," << endl << "t = t + 1" << endl << "if(t<=" << 1/(tStep) << ") reread;";
	guitar << "t = 0" << endl << "system('mkdir gif')" << endl << "load 'graph.gnu'";
	
	//clean up memory
	eFile.close();
	aFile.close();
	dFile.close();
	gFile.close();
	bFile.close();
	EFile.close();
	graph.close();
	guitar.close();
	delete ptr;
	return 0;
}

//calculates psi(x,T) and stores values in guitar.txt
int wire::waveEq(double T) {
	for(double x = 0; x < 100; x++) {
		//calculation
		*ptr = sin(k*x/100-w*T) + 2*num;
		//write to appropriate file
		switch(num) {
			case 0:
				eFile << line << "     " << num << "     " << x/100 << "     " << *ptr << endl;
				break;
			case 1:
				aFile << line << "     " << num << "     " << x/100 << "     " << *ptr << endl;
				break;
			case 2:
				dFile << line << "     " << num << "     " << x/100 << "     " << *ptr << endl;
				break;
			case 3:
				gFile << line << "     " << num << "     " << x/100 << "     " << *ptr << endl;
				break;
			case 4:
				bFile << line << "     " << num << "     " << x/100 << "     " << *ptr << endl;
				break;
			case 5:
				EFile << line << "     " << num << "     " << x/100 << "     " << *ptr << endl;
				break;
		}
		line++;
		ptr = ptr + 1;
	};
	
	return 1;
}

int wire::timeEq() {
	line = 0;
	double t = 0;
	while(t <= 1) {
		waveEq(t);
		ptr = psi;//resets ptr to psi[0]
		t+=tStep; //increase time
	};
	return 1;
}