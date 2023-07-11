//Here begins MonteCarlo.cc

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <math.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#define ranf() \
	((double)rand()/(1.0+(double)RAND_MAX)) // Uniform from interval [0,1) */

int main(int argc, char* argv[])
{
	int    outcome, b=2, count_in=0 , seed=123 ;
	double fraction_in ;

	if(argc>1)   {
		sscanf( argv[1], "%d", &b ) ; // put the first command-line argument in N
	}
	if(argc>2) {
    sscanf( argv[2], "%d", &seed ) ; // put the 2nd argument in seed
	}
	// Write out a summary of parameters
	//cout << "# " << argv[0] << " N=" << N << " seed=" << seed << endl ;
  
	// Initialise random number generator 
	srand(seed);
  
	//calculate what N is needed for sigma = +/- 0.00025 (a difference of 0.005 is then 2sigma = 95%)
	double maxN = ceil(((log(b))*((b-1)-(log(b))))/((b-1)*pow(0.0025, 2)));
	int N = ceil(maxN);
	
	//DEBUG check N
	//cout << "N = " << N << endl;
	
	//open files to be read 
	ifstream test("tmpfile.txt");
	
	//open file to be written to
	ofstream tmpfile("tmpfile.txt");
	ofstream trend("graph.gnu");
	ofstream indots("indots.txt");
	ofstream outdots("outdots.txt");
	ofstream diagram("diagram.gnu");
	
	//edited Monte Carlo method
	for(int n=1; n<=N; n++) {
		double x = (b-1)*ranf() + 1; //  x is a real number in [1,2)
		double y = ranf();
		if (1/x > y) {
			outcome = 1;
		} else {
			outcome = 0;
		}
		count_in += outcome ; 
		//Integer variables must be converted (cast) for correct division
		fraction_in = static_cast<double>(count_in)/n;
		
		//send data directly to file tmpfile.txt
		tmpfile << "Location" << outcome << "\t" << x << "\t" << y << "\t"
			<< count_in << "\t" << n << "\t" << (b-1)*fraction_in << endl;
	}
	
	cout << "ln(" << b << ") = " << fixed << setprecision(2) << (b-1)*fraction_in << endl;
	
	//send instructions for plotting the ln(2) against N graph to graph.gnu
	trend << "f(N) = sqrt((log(" << b << ")*(1-log(" << b << "))/N))" << endl << "set xrange[1:" << N << "]" << endl << "plot log(" << b << ")+f(x) with lines linetype 5, log(" << b << ")-f(x) with lines linetype 5, 'tmpfile.txt' u 5:6 with linespoints, log(" << b << ")";
	
	//split the dots into inside and outside files
	string line;	//stores current line
	
	while (getline (test, line)) {
		if (line.find("Location0") != string::npos) {
			outdots << line << endl;
		} else {
			indots << line << endl;
		}
	}
	
	//send instructions for creating the diagram to diagram.gnu
	diagram << "set xrange[1:" << b << "]" << endl << "plot 'indots.txt' u 2:3 w points lt rgb 'red', 'outdots.txt' u 2:3 w points lt rgb 'blue', 1/x with lines linetype 4";
	
	//close files
	diagram.close();
	trend.close();
	tmpfile.close();
	test.close();
	indots.close();
	outdots.close();
  return 0;
}

