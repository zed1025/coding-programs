#include<iostream>
#include<unordered_set>
using namespace std;
template<typename T>
void showUMS(unordered_multiset<T> ums) {
	for(auto a: ums) {cout << a << " ";} cout << endl;
}
int main() {
	unordered_multiset<int> ums;
	ums.insert({1, 2, 1, 3, 4, 7});
	ums.emplace(4); ums.insert({5, 34, 1, 78});
	showUMS(ums);
	if(!ums.empty()) cout << "unordered_multiset is not empty";
	cout << "\nSize of unordered_multiset is: " << ums.size();
	// using find()
	if(ums.find(78) != ums.end()) cout << "\n78 found in unordered_multiset";
	cout << "\n1 occurs " << ums.count(1) << " times.";
	// equal_range()
	auto x = ums.equal_range(34);
	cout << "\nFor element 34:\tLower Bound=" << *x.first << "\tLower Bound: " << *x.second;
	// erase
	cout << endl;
	showUMS(ums);
	ums.erase(1);
	showUMS(ums);
	ums.erase(ums.begin(), ums.find(3));
	showUMS(ums);
	ums.insert({1, 1, 1, 78, 34, 5, 2});
	showUMS(ums);
	auto it = ums.find(1); // erasing a single instance of items that appear more than once
	if(it != ums.end()) ums.erase(it);
	showUMS(ums);
	// bucket_count(), bucket_size(), bucket(), hash_function()
	// displaying initial parameters
    cout << "\ninitial parameters are: \n";
    cout << "bucketcount() = " << ums.bucket_count() << endl;
    cout << "load factor = " << ums.load_factor() << endl;
    cout << "Max_load_factor = " << ums.max_load_factor() << endl;
    cout << endl;
    // performing rehash
    ums.rehash(200);
    // displaying final parameters
    cout << "\nfinal parameters are: \n";
    cout << "bucketcount() = " << ums.bucket_count() << endl;
    cout << "load factor = " << ums.load_factor() << endl;
    cout << "Max_load_factor = " << ums.max_load_factor() << endl;
    cout << endl;
	return 0;
}