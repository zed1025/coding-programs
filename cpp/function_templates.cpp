#include <iostream>
#include <cstring>

using namespace std;

//function template, returns max of two numbers
template <typename T> //can replace typename with class
T Max(T a, T b) {
	return a < b? b: a;
}

int main() {
	int i=5, j=6, k;
	long l=10, m=5, n;
	k = Max<int>(i, j);
	n = Max<long>(l, m);
	cout << k << endl;
	cout << n << endl;
	return 0;
}


