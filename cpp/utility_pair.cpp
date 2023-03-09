#include<iostream>
#include<utility>
#include<array>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int, string> p1, pair<int, string> p2){
	return p1.first > p2.first;
}
int main() {
	string name[] = {"Amit", "Priya", "Manju Jha", "John", "Jack", "Steven"};
	int age[] = {24, 20, 54, 57, 60, 52};
	// array<pair<int, string>, 6> arr; // not working
	// pair<int, string> arr[6]; //working
	vector<pair<int, string>> arr;
	for(int i=0; i<6; i++) {
		// arr[i] = make_pair(age[i], name[i]);
		arr.push_back(make_pair(age[i], name[i]));
	}
	for(int i=0; i<6; i++) {
		cout << "\nName: " << arr[i].first << "\tAge: " << arr[i].second;
	}
	cout << "\n*********************************************************\n";
	// sort(arr, arr+6, compare); // use with c-array
	sort(arr.begin(), arr.end(), compare);
	for(int i=0; i<6; i++) {
		cout << "\nName: " << arr[i].first << "\tAge: " << arr[i].second;
	}
}	