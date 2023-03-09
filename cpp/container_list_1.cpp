#include<iostream>
#include<list>
using namespace std;
int main() {
	list<int> l1, l2;
	for(int i=0; i<5; i++) {
		l1.push_back(i*2); l2.push_back(i*3);
	}
	cout << "\nList 1 contents: "; 
	for(auto i=l1.begin(); i!=l1.end(); ++i) {cout << *i << " ";}
	cout << "\nList 2 contents: "; 
	for(auto i=l2.begin(); i!=l2.end(); ++i) {cout << *i << " ";}
	cout << "\nl1.front(): " << l1.front();
	cout << "\nl1.back(): " << l1.back();
	cout << "\nl1.pop_front: "; l1.pop_front();
	cout << "\nList 1 contents: "; 
	for(auto i=l1.begin(); i!=l1.end(); ++i) {cout << *i << " ";}
	cout << "\nl1.pop_back: "; l1.pop_back();
	cout << "\nList 1 contents: "; 
	for(auto i=l1.begin(); i!=l1.end(); ++i) {cout << *i << " ";}
	cout << "\nReversing l2: "; l2.reverse();
	cout << "\nList 2 contents: "; 
	for(auto i=l2.begin(); i!=l2.end(); ++i) {cout << *i << " ";}
	cout << "\nSorting l2: "; l2.sort();
	cout << "\nList 2 contents: "; 
	for(auto i=l2.begin(); i!=l2.end(); ++i) {cout << *i << " ";}
}