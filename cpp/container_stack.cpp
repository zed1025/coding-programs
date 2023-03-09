#include <iostream> 
#include <stack> 
using namespace std;
int main() {
    stack<int> stack;
    stack.push(21);
    stack.push(22);
    stack.push(24);
    stack.push(25);
    stack.pop();
    stack.pop();
    stack.emplace(1);
    stack.emplace(2);
    while (!stack.empty()) {
        cout << ' ' << stack.top();
        stack.pop();
    } // 2 1 22 21
}