#include <iostream>
#include <string>
#include <vector>
using namespace std;

//create student class


class College {
	public:
		string symbol = "";
		//string motto = "Hinc lucem et pocula sacra";
		int date = 0;
		string college = "";

	void print() {
		cout << " at " << symbol << " college." << endl;
	}
	
	void printDate() {
		cout << " at " << college << " college, founded in " << date << "." << endl;
	}
	
	//constructor
	College(string s) {
		symbol = s;
	}
};

class Robinson: public College{
	public:
		//string symbol = "R";
		string symbol = "Robinson";
		string college = "Robinson";
		int date = 1977;
		
	void print() {
		cout << " at " << college << " college, founded in " << date << "." << endl;
	}
	
	Robinson(string s) : College(s){
		symbol = s;
	}
};


class Student {
	public:
		string name;
		int year;
		string tripos;
		//string college = "";
		//int date = 0;
		//string motto = "";
		
		void print() {
			cout << name << " is a " << year << " year " << tripos << " student"; // << " student at " << college;
			
		}
	//constructor
	Student(string n, int y, string t) {	 //, string m) {
		name = n;
		year = y;
		tripos = t;
		//letter = c;
		//date = d;
		//motto = m;
	}
};

//functions

//Robinson makeR() {
	//return Robinson();
//}

//main
int main() {
	
	int i = 1;
	//set of students
	vector <Student> roster;
	vector <College> housing;
	vector <Robinson> bricks;
	vector <string> orderCol;
	vector <int> orderNum;
	//int count = 0;
	
	while (i != 0) {
		//variables
		string name = "";
		int year = 0;
		string tripos = "";
		string symbol = "";
		
		
		//count++;
		string ans = "";
		//input student details
		
		cout << endl;
		
		cout << "What's your name?" << endl;
		getline(cin, name);
		cout << endl;
		
		while (year < 1 or year > 4) {
			cout << "Which year are you in (1-4)?" << endl;
			cin >> year;
			cout << endl;
		}
		
		cin.sync();
		
		cout << "Which tripos do you study?" << endl;
		getline(cin, tripos);
		cout << endl;
		
		cout << "Which college are you at (e.g. R)?" << endl;
		getline(cin, symbol);
		cout << endl;
		
		//College college("symbol");
		
		College college(symbol);
		Robinson r(symbol);
		
		if (symbol == "R") {
			bricks.push_back(r);
			orderCol.push_back("r");
			orderNum.push_back(bricks.size()-1);
		} else {
			housing.push_back(college);
			orderCol.push_back("c");
			orderNum.push_back(housing.size()-1);
		}
		
		Student stu(name, year, tripos);
		roster.push_back(stu);
		//ewan.name = "Ewan Chamberlain";
		//ewan.year = 2;
		//ewan.tripos = "Natural Sciences";
		
		//for (int x = 0; x <= roster.size(); x++) {
		//	print orderNum[x];
		///	print orderCol[x];
		//}
		
		cout << "add another student (y/n)?" << endl;
		cin >> ans;
		if (ans == "n") {
			i = 0;
		}
	}	
	
	for (int x = 0; x < roster.size(); x++) {
		roster[x].print();
		
		if (orderCol[x] == "r") {
			bricks[orderNum[x]].print();
		} else {
			housing[orderNum[x]].print();
		}
		
	}
	return 0;
}


