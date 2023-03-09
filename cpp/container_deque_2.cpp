#include <deque>
#include <iostream>
#include <vector>
using namespace std;
void showdq(deque<int> g) { for (auto it = g.begin(); it != g.end(); ++it) {cout << *it << " ";} cout << endl; }
int main() {
    deque<int> dq = {1, 2, 3, 4};
    showdq(dq);
    // insert
    deque<int> mydeque;
    for (int i=1; i<6; i++) mydeque.push_back(i); // 1 2 3 4 5, set some initial values
    deque<int>::iterator it = mydeque.begin();
    ++it;
    it = mydeque.insert (it,10);                  // 1 10 2 3 4 5, "it" now points to the newly inserted 10
    showdq(mydeque);
    mydeque.insert(it,2,20);                     // 1 20 20 10 2 3 4 5, "it" no longer valid!
    showdq(mydeque);
    it = mydeque.begin()+2;
    vector<int> myvector (2,30);
    mydeque.insert (it,myvector.begin(),myvector.end()); // 1 20 30 30 20 10 2 3 4 5
    showdq(mydeque);
    // assign
    dq.assign({1, 2, 3, 4});
    showdq(dq);
    // operator []
    cout << dq[0] << endl;
    return 0;
}