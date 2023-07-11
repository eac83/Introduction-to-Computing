#include <iostream>
#include <fstream>
#include <cmath>
#include <typeinfo>
#include <functional>
using namespace std;

//global variables
float c = 0.0; //stores number whose sqrt is to be found

//functions
template <typename type>
type f(type x);	//calculates quadratic f(x) = c - x^2
void newp(float &p, float &p0); //calculates new value of p for newton-raphson
float df(float x); //calculates f'(x) = -2x
void output(int i, double p, double e); //outputs current estimate of sqrt in bijection
void output(int i, float p); //outputs current estimate of sqrt in n-r
void sqrt(double &p, double a, double b, double &e); //calculates by bijection
void sqrt(float &p, float &p0, float &e); //calculates by n-r
void error(function<float(float)> diff, float &e, float p);

//open files
ofstream bout("bijection.txt"); //stores each run of bijection method
ofstream nout("newton-raphson.txt"); // stores each run of n-r method


//main function
int main(int argc, char *argv[]) {
	
	//variables
	double p = 1.0; //stores current bijection estimate
	float p2 = 1.0; //stores current n-r estimate
	float p0 = 1.0; //stores old n-r estimate
	double a = 0.1; //stores lower bound of bijection estimate
	double b = 0; //stores upper bound of bijection estimate
	double e = 0; //stores error of bijection estimate
	char method = 'a'; //stores choice of method (N or n for newton-raphson, B or b bijection, blank or other characters do both)
	float e2 = 0; //stores error of n-r estimate
	
	//input
	sscanf(argv[1], "%f", &c); //takes first argument from command line and stores it in c
	if (argc > 2) {sscanf(argv[2], "%c", &method);} //takes second argument from command line and stores it in method
	
	//processing
	b = 2 * c; //sets b to be greater than c
	p2 = c / 2;
	
	//do newton-raphson?
	if(method == 'N' or method == 'n') {
		goto bijec;
	} else {
		sqrt(p, a, b, e);
	}
	
	//do bijection?
	bijec:
	if(method == 'B' or method == 'b') {
		goto tru;
	} else {
		sqrt(p2, p0, e2);
	}
	
	tru:	
	cout << "True square root of " << c << " is " << sqrt(c) << endl;
	
	//clean up memory
	bout.close();
	nout.close();
	
	return 0;
}

//function definitions
void newp(float &p, float &p0) {
	p0 = p;
	p = p - f<float>(p) / df(p);
}

template <typename type>
type f(type x) {
	return (c - x*x);
}

float df(float x) {
	return (-2*x);
}

void output(int i, double p, double e){
	bout << i << ": Square root of " << c << " is " << p << "+/-" << e << endl;
}

void output(int i, float p, float e) {
	nout << i << ": Square root of " << c << " is " << p << "+/-" << e << endl;
}

void sqrt(double &p, double a, double b, double &e) {
	for (int x = 0; x < 100; x++) {
			p = (a + b) / 2;
			if ( f<double>(a) * f<double>(p) <= 0 ) {
				b = p;
			} else {
				a = p;
			};
			
			e = (b - a) / 2;
			output(x, p, e);
		};
		//output
		cout << "Bijection estimated square root of " << c << " is " << p << "+/-" << e << endl;
}

void sqrt(float &p, float &p0, float &e) {
	for(int i = 0; i < 100; i++) {
		if (p == p0) { 
			break;
		} else {
			newp(p, p0);
			
			if(i == 0) {
				e = abs(sqrt(c) - p);
			} else {
				error(df, e, p);
			}
			
			output(i, p, e);
		}
	}
		//output
		cout << "Newton-Raphson estimated square root of " << c << " is " << p << "+/-" << e << endl;	
}

void error(function<float(float)> diff, float &e, float p) {
	e = pow(e,2)*abs(1 / diff(p));
}