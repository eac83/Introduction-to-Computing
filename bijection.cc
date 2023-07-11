#include <iostream>
using namespace std;

double f(double x);

int c = 0;

double a = 0.1;

double b = 2 * c;

int main(int argc, char *argv[]) {
	
	sscanf(argv[1], "%d", &c);
	
	b = 2 * c;
	
	double p = 0;
	
	for (int x = 0; x < 100; x++) {
		p = (a + b) / 2;
		if ( f(a) * f(p) <= 0 ) {
			b = p;
		} else {
			a = p;
		};
		
		double e = (b - a) / 2;
		cout << x << ": Square root of " << c << " is " << p << "+/-" << e << endl;
	};
	
	
	

	return 0;
}

double f(double x) {
	return (c - x*x);
};