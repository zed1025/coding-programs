#include<iostream>
#include<vector>
#include<iterator>
using namespace std;
int main() {
	vector<int> v1;
	for(int i=0; i<=5; i++) { v1.push_back(i+1); }
	cout << "Output of begin() and end()\n";
	for(auto it=v1.begin(); it != v1.end(); ++it) { cout << *it << " "; }
	cout << "\nOutput of cbegin() and cend()\n";
	for(auto it=v1.cbegin(); it != v1.cend(); ++it) { cout << *it << " "; }
	cout << "\nOutput of rbegin() and rend()\n";
	for(auto it=v1.rbegin(); it!=v1.rend(); it++) { cout << *it << " "; }
	cout << "\nOutput of crbegin() and crend()\n";
	for(auto it=v1.crbegin(); it!=v1.crend(); ++it) { cout << *it << " "; }
	return 0;
}