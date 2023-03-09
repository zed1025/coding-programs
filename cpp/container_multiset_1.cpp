#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
void showMS(multiset<int> m) {for(auto i: m) {cout << i << " ";};}
int main() {
	multiset<int> ms;
	ms.insert({20, 30, 40, 60, 20, 50});
	vector<int> v = {10, 50, 20};
	ms.insert(v.begin(), v.end());
	showMS(ms); cout << endl;
	// removing all elements less than 20
	ms.erase(ms.begin(), ms.find(20)); // 10 will be removed
	showMS(ms); cout << endl;
	// remove all elements with value 50
	ms.erase(50);
	showMS(ms); cout << endl;
	// lower bound and upper bound for multiset ms
    cout << "\nms.lower_bound(40) : " << *ms.lower_bound(40) << endl;
    cout << "ms.upper_bound(40) : " << *ms.upper_bound(40) << endl;
    // remove only one instance of duplicate elements
    showMS(ms); cout << endl;
    ms.erase(ms.find(20));
    showMS(ms); cout << endl;
    // erasing a specific element - pass the iterator to the element as a single argument to erase()
    multiset<int>::iterator it2 = ms.begin();
    ms.erase(it2);
    showMS(ms); cout << endl;
    // equal range
    ms.insert({20, 20, 40, 70, 20});
    showMS(ms); cout << endl;
    auto it = ms.equal_range(40);
    cout << "\nThe lower bound of 40 is " << *it.first;
    cout << "\nThe upper bound of 40 is " << *it.second;
    it = ms.equal_range(10);
    cout << "\nThe lower bound of 10 is " << *it.first;
    cout << "\nThe upper bound of 10 is " << *it.second;
    it = ms.equal_range(20);
    cout << "\nThe lower bound of 20 is " << *it.first;
    cout << "\nThe upper bound of 20 is " << *it.second << endl; 
    // removing all 20's and 40's(they occour mutiple times) using equal_range
    showMS(ms); cout << endl;
    it = ms.equal_range(20);
    ms.erase(it.first, it.second);
    showMS(ms); cout << endl;
    it = ms.equal_range(40);
    ms.erase(it.first, it.second);
    showMS(ms); cout << endl;
    return 0;
}
