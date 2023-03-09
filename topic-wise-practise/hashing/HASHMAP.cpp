
#include<bits/stdc++.h>
using namespace std;

int main() {

    //creation
    unordered_map<string, int> m; //duplicate keys not allowed

    //insertion
    pair<string, int> p = make_pair("amit", 3);
    m.insert(p);
    pair<string, int> p2("priya", 10);
    m.insert(p2);
    m["sneha"] = 5; //new key-value creation
    m["sneha"] = 3; //value updated for key "sneha"

    //searching
    cout << m["sneha"] << endl;
    cout << m.at("amit") << endl;

    // cout << m.at("unknownKey") << endl; //ERROR
    cout << m["unknownKey"] << endl; //output=0, why, a new entry is created and its value is printed

    //NOTE: the order in which line 22 and 23 are executed influences the the output

    //size
    cout << "Size: " <<m.size() << endl;

    //check if key present
    //count return 1 if key is present
    cout << m.count("bro") << endl;
    cout << m.count("amit") << endl;

    //erase
    m.erase("amit");
    cout << "Size: " << m.size() << endl;

    //iterating through the map
    for(auto i: m) {
        cout << i.first << ": " << i.second << endl;
    }
    //using iterators
    cout << "\nUsing Iterators: \n";
    unordered_map<string, int>::iterator it = m.begin();
    while(it!=m.end()) {
        cout << it->first << ": " << it->second << endl;
        it++;
    }
}   