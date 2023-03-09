#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> g1;
	for(int i=0; i<=10; i++) {g1.push_back(i+2);} 
	for(auto i=g1.begin(); i!=g1.end(); ++i) {cout << *i << " ";}
	cout << "\nReference operator [g] : g1[2] = " << g1[2];
    cout << "\nat : g1.at(4) = " << g1.at(4);
    cout << "\nfront() : g1.front() = " << g1.front();
    cout << "\nback() : g1.back() = " << g1.back();
    // pointer to the first element
    int* pos = g1.data();
    cout << "\nThe first element is " << *pos;
    return 0;
}