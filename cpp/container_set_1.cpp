#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
void showSett(set<int> s) { for(auto i: s) {cout << i << " ";} }
void showSett2(set<int, greater<int>> s) { for(auto i: s) {cout << i << " ";} }
int main() {
    // basics
    set<int> s;  // ascending
    set<int, greater<int>> s2;   // descending
    s.insert(25);
    s.insert(26);
    s.emplace(23);
    s.emplace(26);
    s.emplace(25);
    showSett(s); cout << endl;
    s2.insert(s.begin(), s.end());
    showSett2(s2);
    cout << "\nSize of set: " << s.size();
    cout << "\nMax size of set: " << s.max_size() << endl;
    s.insert({1, 2, 3, 4});
    showSett(s);
    // IMP: removing all elements below a certain element in set
    cout << "\nRemoving all elements less than 23: ";
    s.erase(s.begin(), s.find(23));
    showSett(s);
    // removing element with value 23
    int num = s.erase(23);
    cout << "\nnum=" << num << endl;
    showSett(s); cout << endl; 
    // lower and upper bound for sets
    s.insert({40, 30, 60, 20, 50});
    showSett(s);
    // NOTE: lower_bound and upper_bound will return the same iterator if the value passed is not present in the container, which is the case here.
    cout << "\ns.lower_bound(25) = " << *s.lower_bound(25);
    cout << "\ns.upper_bound(25) = " << *s.upper_bound(25); cout << endl;
    // equal_range
    showSett(s);
    auto it = s.equal_range(26); //returns a pair of iterators
    cout << "\nLower Bound for 26 is: " << *it.first;
    cout << "\nUpper Bound for 26 is: " << *it.second;
    it = s.equal_range(100);
    cout << "\nLower Bound for 100 is: " << *it.first;
    cout << "\nUpper Bound for 100 is: " << *it.second;
    it = s.equal_range(19);
    cout << "\nLower Bound for 19 is: " << *it.first;
    cout << "\nUpper Bound for 19 is: " << *it.second;
    it = s.equal_range(29);
    cout << "\nLower Bound for 29 is: " << *it.first;
    cout << "\nUpper Bound for 29 is: " << *it.second;
    return 0;
}