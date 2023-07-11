//Here begins Students and Colleges.cpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//classes

//college class - stores generic information about the student's college
class College {
	public:
		string symbol = "";
		int date = 0;
		string college = "";
	
	//print out sentence at output
	void print() {
		cout << " at " << symbol << " college." << endl;
	}
	
	//constructor
	College(string s) {
		symbol = s;
	}
};

class Robinson: public College{
	public:
		string symbol = "Robinson";
		string college = "Robinson";
		int date = 1977;
	
	//prints out sentence at output
	void print() {
		cout << " at " << college << " college, founded in " << date << "." << endl;
	}
	
	//constructor
	Robinson(string s) : College(s){
		symbol = s;
	}
};


class Student {
	public:
		string name;
		int year;
		string tripos;
		
	//prints out sentence at output
	void print() {
		cout << name << " is a " << year << " year " << tripos << " student"; 
		
	}
		
	//constructor
	Student(string n, int y, string t) {
		name = n;
		year = y;
		tripos = t;
	}
};

//main
int main() {
	
	//while loop variable
	int i = 1;
	//vectors
	vector <Student> roster;	//stores information about the student
	vector <College> housing;	//stores information about the student's college
	vector <Robinson> bricks;	//stores information about Robinson college
	vector <string> orderCol;	//stores which college a student is at
	vector <int> orderNum;		//stores which college a student is at 
	
	while (i != 0) {
		//variables
		string name = "";		//student info
		int year = 0;
		string tripos = "";
		string symbol = "";		//college info
		
		//for the end of the loop
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
		
		//create objects for each college
		College college(symbol);
		Robinson r(symbol);
		
		//store object in the vector
		if (symbol == "R") {
			bricks.push_back(r);
			orderCol.push_back("r");
			orderNum.push_back(bricks.size()-1);
		} else {
			housing.push_back(college);
			orderCol.push_back("c");
			orderNum.push_back(housing.size()-1);
		}
		
		//store student info in vector
		Student stu(name, year, tripos);
		roster.push_back(stu);
		
		//continue loop?
		cout << "add another student (y/n)?" << endl;
		cin >> ans;
		cin.sync();
		if (ans == "n") {
			i = 0;
		}
	}	
	
	
	//output
	for (int x = 0; x < roster.size(); x++) {
		roster[x].print();	//outputs student half of sentence
		
		//outputs college half of sentence
		if (orderCol[x] == "r") {
			bricks[orderNum[x]].print();
		} else {
			housing[orderNum[x]].print();
		}
		
	}
	return 0;
}


