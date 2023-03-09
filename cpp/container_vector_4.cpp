#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v;
	v.assign(5, 10); // [10 10 10 10 10]
	cout << "Vector elements: ";
	for(auto i=v.begin(); i!=v.end(); ++i) {cout << *i << " ";}
	v.push_back(15); // [10 10 10 10 10 15]
	v.pop_back(); // [10 10 10 10 10]
	v.insert(v.begin(), 5); // [5 10 10 10 10 10], insert 5 at the beginning
	v.erase(v.begin()); // [10 10 10 10 10], remove first element
	v.emplace(v.begin(), 5); // [5 10 10 10 10 10], insert 5 at the beginning
	v.emplace_back(20); // [5 10 10 10 10 10 20], insert 20 at the end
	cout << "\nVector elements: ";
	for(auto i=v.begin(); i!=v.end(); ++i) {cout << *i << " ";}
	v.clear(); // [], erase the vector
	cout << "\nVector size after erase(): " << v.size(); // 0
	vector<int> v1={1, 2}, v2={3, 4};
	cout << "\nVector, v1 elements before swap: "; // [1 2]
	for(auto i=v1.begin(); i!=v1.end(); ++i) {cout << *i << " ";}
	cout << "\nVector, v2 elements before swap: "; // [3 4]
	for(auto i=v2.begin(); i!=v2.end(); ++i) {cout << *i << " ";}
	v1.swap(v2);
	cout << "\nVector, v1 elements after swap: "; // [3 4]
	for(auto i=v1.begin(); i!=v1.end(); ++i) {cout << *i << " ";}
	cout << "\nVector, v2 elements after swap: "; // [1 2]
	for(auto i=v2.begin(); i!=v2.end(); ++i) {cout << *i << " ";}
	return 0;
}