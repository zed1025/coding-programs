#include<iostream>
#include<map>
using namespace std;
void printMap(map<int, int> m) {for(auto it=m.begin(); it!=m.end(); ++it) { cout << "\n" << it->first << ": " << it->second; }}
int main(){
	map<int ,int> m;
	// inserting into a map
	m.insert({1, 100});
	m.insert(pair<int, int>(2, 200));
	m.emplace(4, 400); // no need for curly braces
	m.insert({3, 300});
	printMap(m); cout << endl;
	// remove all elements up to element with key=3 in map m
	cout << "\nremove all elements up to element with key=3 in map m";
	m.erase(m.begin(), m.find(3));
	printMap(m); cout << endl;
	m.insert({4, 500}); // cannot insert because key=4 already exists
	m.insert({4, 600});	// cannot insert
	printMap(m); cout << endl;
	//remove element whose key is known
	m.insert({88, 8800});
	printMap(m); cout << endl;
	m.erase(88); // remove element with key=88
	printMap(m); cout << endl;
	// lower bound and upper bound for map m, key = 5
	m.insert({6, 600}); m.insert({7, 700}); m.insert({5, 500});
	cout << "m.lower_bound(5) : " << "\tKEY = ";
    cout << m.lower_bound(5)->first << '\t';
    cout << "\tELEMENT = " << m.lower_bound(5)->second << endl;
    cout << "m.upper_bound(5) : " << "\tKEY = ";
    cout << m.upper_bound(5)->first << '\t';
    cout << "\tELEMENT = " << m.upper_bound(5)->second << endl;
    // count
    if(m.count(5)) cout << "Key 5 is present\n";
    if(!m.count(100)) cout << "Key 100 is not present\n";
    // equal_range
    pair<map<int, int>::iterator, map<int, int>::iterator> it;
    it = m.equal_range(4);
    cout << "\nThe lower bound is " << it.first->first << ":" << it.first->second;
    cout << "\nThe upper bound is " << it.second->first << ":" << it.second->second;
    it = m.equal_range(2);
    cout << "\nThe lower bound is " << it.first->first << ":" << it.first->second;
    cout << "\nThe upper bound is " << it.second->first << ":" << it.second->second;
    it = m.equal_range(8);
    cout << "\nThe lower bound is " << it.first->first << ":" << it.first->second;
    cout << "\nThe upper bound is " << it.second->first << ":" << it.second->second;
    // find()
    map<int, int>::iterator it2 = m.find(4); // if not found, it will (return size_of_map:0)
    cout << "\nResult of m.find(4)->  " << it2->first << ": " << it2->second;
    // at()
    printMap(m); cout << endl;
    cout << m.at(5) << endl;
    return 0;
}