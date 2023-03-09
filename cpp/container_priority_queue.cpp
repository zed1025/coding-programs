#include<iostream>
#include<queue> // for priority queue
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	priority_queue<int> pq1; // max priority queue, max-heap
	priority_queue<int, vector<int>, greater<int>> pq2; // min priority queue, min-heap
	pq1.push(10);
	pq1.emplace(2);
	pq1.push(23);
	cout << "\nMax Queue top: " << pq1.top();
	// pq2.swap(pq1); //error cannot swap min-heap with max-heap
	pq2.push(10); pq2.push(2); pq2.push(23);
	cout << "\nMin queue top: " << pq2.top();
	cout << "\nSize of pq2: " << pq2.size();
}