#include<iostream>
#include<algorithm>
using namespace std;
struct Interval {
	int start, end;
};
bool compareInterval(Interval i1, Interval i2) {
	return (i1.start < i2.start); //sorting according to the first element 'start'
}
int main() {
	Interval arr[] = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
	int n = sizeof(arr) / sizeof(arr[0]);
	sort(arr, arr + n, compareInterval); // sort the intervals in increasing order of start time
	cout << "Intervals sorted by start time : \n";
	for (int i = 0; i < n; i++)
		cout << "[" << arr[i].start << "," << arr[i].end << "] ";
	return 0;
}
