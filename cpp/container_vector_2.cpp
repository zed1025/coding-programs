#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v1;
	for(int i=0; i<=5; i++) {v1.push_back(i+1);} // [1 2 3 4 5 6]
	cout << "Size of vector: " << v1.size(); // Size of vector: 6
	cout << "\nCapacity: " << v1.capacity(); // Capacity: 8
	cout << "\nMax Size: " << v1.max_size(); // Max Size: 2305843009213693951
	// resizing the vector to size 4
	v1.resize(4);
	cout << "\nSize: " << v1.size(); // Size: 4
	cout << "\nContents of vector after resizing: ";
	for(auto it=v1.begin(); it!=v1.end(); ++it) {cout << *it << " ";} // [1 2 3 4]
	//checking if vector is empty
	if(v1.empty()) {cout << "\nVector is empty.";}
	else {cout << "\nVector is not empty.";}
	//shrinking the vector
	v1.shrink_to_fit();
	cout << "\nContents of vector after shrink_to_fit: "; 
	for(auto it=v1.begin(); it!=v1.end(); ++it) {cout << *it << " ";} // [1 2 3 4]
	return 0; 
}