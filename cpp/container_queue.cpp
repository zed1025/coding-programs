#include<iostream>
#include<queue>
using namespace std;
int main() {
	queue<int> q;
	q.push(10);
	q.emplace(20);
	q.push(30);
	q.push(40);
	cout << "\nQueue size: " << q.size();
	cout << "\nFront of queue: " << q.front();
	cout << "\nBack of queue: " << q.back();
	if(!q.empty()) cout << "\nQueue not empty.\n";
	queue<int> q2 = q;
	while(!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}cout << endl;
}