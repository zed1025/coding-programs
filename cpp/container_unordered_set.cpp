#include<iostream>
#include<unordered_set>
using namespace std;
template <typename T>
void printUS(unordered_set<T> us) {
	for(auto x: us) { cout << x << " "; } cout << endl;
}
int main() {
	unordered_set<string> uss;
	uss.insert("coding"); uss.insert("in");
	uss.emplace("c++");
	uss.emplace("is"); uss.emplace("fast");
	uss.emplace("is"); uss.emplace("fast");
	printUS(uss); // randomly printed items
	// find, find returns end iterator if key is not found, else it returns iterator to that key
	if (uss.find("in") == uss.end()) { cout << "in not found" << endl; } 
	else { cout << "in found"; }
	// count() used to check if element present or not
	cout << "\n\'is\' present in the unordered_set: " << uss.count("is");
	// bucket_size() and bucket_count()
	cout << "\nBucket count is: " << uss.bucket_count();
	cout << "\nNumber of elements in bucket 0 is: " << uss.bucket_size(0);
	cout << "\nNumber of elements in the unordered_set: " << uss.size();
	cout << "\nunordered_set is empty?: " << uss.empty(); cout << endl;
	// equal range
	unordered_set<int> sample; sample.insert({ 20, 30, 40 });
	printUS(sample);
	auto range = sample.equal_range(30);
	cout << "Lower Bound: " << *range.first << " \tUpper Bound: " << *range.second;
	// hash_function()
	unordered_set<string>::hasher fn = uss.hash_function();
	cout << "\nHash for c++: " << fn("c++");
	unordered_set<string> uss2; 
	unordered_set<string>::hasher fn2 = uss2.hash_function();
	cout << "\nHash for c++: " << fn2("c++");
	// bucket()
	cout << "\nc++ is in bucket: " << uss.bucket("c++");
	cout << "\nLoad factor of the unordered_set: " << uss.load_factor();
	cout << "\nMax Load factor of the unordered_set: " << uss.max_load_factor();
	return 0;
}