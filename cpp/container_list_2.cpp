#include<iostream>
#include<list>
using namespace std;
void showList(list<int> l) {
	cout << "\nContents of list: ";
	for(auto i=l.begin(); i!=l.end(); ++i) {cout << *i << " ";}
}
bool even(const int& value) { return (value % 2) == 0; }
int main() {
	list<int> l1 = {1, 2, 3, 4};
	showList(l1);
	// insert()
	list<int>::iterator it = l1.begin(), it2;
	advance(it, 4); // iterator to point to 5th position
	l1.insert(it, 55);
	showList(l1);
	l1.insert(it, 2, 66); // insert 66, 2 times at the 6th position
	showList(l1);
	// erase
	it = l1.begin(); advance(it, 4); // 'it' is pointing to 5th element, 55
	l1.erase(it);
	showList(l1);
	it = l1.begin(); advance(it, 4);
	it2 = l1.end(); 
	l1.erase(it, it2); // removing a range of elements, both the 66
	showList(l1);
	// unique, only works on sorted list
	it = l1.begin(); advance(it, 4);
	l1.insert(it, 7, 5); // insert 5, 7 times at the end of list
	showList(l1);
	l1.unique();
	showList(l1);
	// remove
	it = l1.begin();
	l1.insert(it, 2, 5);
	showList(l1);
	l1.remove(5);
	showList(l1);
	//remove_if
	list<int> mylist = { 1, 2, 2, 2, 5, 6, 7 };
	showList(mylist);
	mylist.remove_if(even);
	showList(mylist);
	//clear
	showList(mylist);
	mylist.clear();
	showList(mylist);
	return 0;
}