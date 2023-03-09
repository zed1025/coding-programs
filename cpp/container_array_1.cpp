#include<iostream>
#include<array> // for array, at()
#include<tuple> // for get()
using namespace std;
void showArr(array<int, 6> a) {
	for(int i=0; i<a.size(); i++) cout << a[i] << " "; // can also use, get<0>(a) or a.at(i)
}
int main() {
	array<int, 6> ar = {1, 2, 3, 4, 5, 6};
	showArr(ar);
	cout << "\nFront of array: " << ar.front();
	cout << "\nBack of array: " << ar.back();
	cout << "\nSize of array: " << ar.size();
	cout << "\nMax Size(size with which array is declared): " << ar.max_size();
	if (!ar.empty()) cout << "\nArray is not empty\n";
	// fill
	array<int, 6> ar2;
	ar2.fill(34);
	showArr(ar2);
}