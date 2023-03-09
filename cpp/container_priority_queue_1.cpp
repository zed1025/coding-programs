#include<iostream>
#include<queue> // for priority queue
#include<vector>
#define ROW 5
#define COL 2
using namespace std;
struct Person{
	int Age;
	float Height;
	Person(int age, float height):Age(age), Height(height) {}
};
// the following struct implements overloading the default comparator
struct CompareHeight { 
	bool operator()(Person p1, Person p2) {
		return p1.Height < p2.Height;
	}
};
int main() {
	priority_queue<Person, vector<Person>, CompareHeight> Q; // heap type depends on comparator function, here max-heap
	float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 }, { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } };
	for (int i = 0; i < ROW; ++i) {
        Q.push(Person(arr[i][0], arr[i][1]));
    }
    while (!Q.empty()) {
        Person p = Q.top();
        Q.pop();
        cout << p.Age << " " << p.Height << "\n";
    }
    return 0;
}