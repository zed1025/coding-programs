#include<iostream>
#include<queue> // for priority queue
#include<vector>
using namespace std;
#define ROW 5
#define COL 2
class Person {
public:
	int age;
	float height;
	Person(int age, float height) : age(age), height(height) {}
};
// overload the '<' operator 
bool operator <(Person p1, Person p2) {
	return p1.height < p2.height; // change '<' to '>' to reverse priority
}
int main() {
	priority_queue<Person> Q; // max-heap
	float arr[ROW][COL] = { { 30, 5.5 }, { 25, 5 }, { 20, 6 }, { 33, 6.1 }, { 23, 5.6 } };
	for (int i = 0; i < ROW; ++i) {
        Q.push(Person(arr[i][0], arr[i][1]));
    }
    while (!Q.empty()) {
        Person p = Q.top();
        Q.pop();
        cout << p.age << " " << p.height << "\n";
    }
    return 0;
}