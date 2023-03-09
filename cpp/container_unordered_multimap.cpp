#include<iostream>
#include<unordered_map>
using namespace std;
template <typename T, typename U>
void showUMM(unordered_multimap<T, U> umm) {
	for(auto it=umm.begin(); it!=umm.end(); ++it) {
		cout << it->first << ": " << it->second << endl;
	}cout << endl;
}
int main(){
	unordered_multimap<string, int> umm;
	umm.insert({{"Amit", 1}, {"Priya", 2}});
	umm.emplace("Manju", 3);
	showUMM(umm);
	return 0;
}