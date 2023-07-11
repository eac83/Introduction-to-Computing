#include <iostream>
using namespace std;

template <typename type>
type getMax (type a, type b) {
	return (a>b?a:b);
}

int main() {
	int x = 1;
	int y = 2;
	float a = 1.3;
	float b = 2.5;
	int i = 0;
	float f = 0;
	
	i = getMax<int>(x, y);
	f = getMax<float>(a, b);
	
	cout << i << endl;
	cout << f << endl;
}

void inc(int &n) {
	n++;
}