#include<iostream>
using namespace std;
int main() {
	auto operation = [](int a, int b, char op) -> double {
		if(op == 's') {
			return a+b;
		} else {
			return (a+b)/2.0;
		}
	};
	int n1=1, n2=2;
	auto sum = operation(n1, n2, 's');
	cout << sum << endl;
	auto avg = operation(n1, n2, 'a');
	cout << avg << endl;
	return 0;
}