#include<iostream>
#include<forward_list>
using namespace std;
void showList(forward_list<int> l) {
	cout << "\nContents of list: ";
	for(auto i=l.begin(); i!=l.end(); ++i) {cout << *i << " ";}
}
int main() {
	forward_list<int> fl1, fl2;
	fl1.assign({5, 3, 2, 4});
	fl2.assign(fl1.begin(), fl1.end());
	showList(fl1);
	showList(fl2);
	//sort 
	fl1.sort();
	showList(fl1); 
	fl1.push_front(1);
	fl1.emplace_front(0);
	showList(fl1);
	fl1.pop_front();
	showList(fl1);
	// insert_after & emplace after
	forward_list<int>::iterator ptr;
	ptr = fl1.insert_after(fl1.begin(), {7, 8}); // inserts one/more elements after the first element
	showList(fl1);
	ptr = fl1.emplace_after(ptr, 999); // insert 999 after ptr
	showList(fl1);
	ptr = fl1.erase_after(ptr); // erases a single element after ptr
	showList(fl1);
	ptr = fl1.erase_after(ptr, fl1.end()); // erases value in a range
	showList(fl1);
	//remove
	fl1.remove(999); // removes all occurence of 999
	showList(fl1);
	//remove_if
	fl1.push_front(67);
	fl1.push_front(787);
	showList(fl1);
	fl1.remove_if([](int x) {return x>50;});
	showList(fl1);
	// clear
	fl2.clear();
	showList(fl2);
	// splice after
	fl2.assign({55, 66});
	fl2.splice_after(fl2.begin(), fl1); //shift elements from fl1 to fl2 after the first element of fl2
	showList(fl2);
}	