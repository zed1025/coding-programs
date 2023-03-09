#include<iostream>
#include<map>
using namespace std;
void printMM(multimap<int, int> mm) {
	for(auto it=mm.begin(); it!=mm.end(); ++it){
		cout << it->first << ": " << it->second << "\n";
	} cout << endl;
}
int main() {
	multimap<int, int> mm;
	mm.insert({1, 100});
	mm.emplace(2, 200);
	mm.insert(pair<int, int>(3, 300));
	mm.insert({3, 3000});
	mm.emplace(4, 400);
	printMM(mm); 
	// count
	cout << "Number of key-value pairs with key=3: " << mm.count(3) << endl;
	// remove all elements up to key with value 3 in mm
	mm.erase(mm.begin(), mm.find(3));
	printMM(mm); 
	// remove all elements with key = 3
	mm.erase(3);
	printMM(mm);
	// lower bound and upper bound for multimap mm key = 5
	mm.emplace(1, 100); mm.emplace(6, 600); mm.emplace(5, 500);
	cout << "mm.lower_bound(5) : " << "\tKEY = ";
    cout << mm.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = " << mm.lower_bound(5)->second << endl;
    cout << "mm.upper_bound(5) : " << "\tKEY = ";
    cout << mm.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = " << mm.upper_bound(5)->second << endl;
    // other rules for emplace same as map
 	return 0;   
 }