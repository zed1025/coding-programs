// https://www.interviewbit.com/problems/large-factorial/
#include<bits/stdc++.h>
using namespace std;
int fact(int n) {
	if (n==1) return 1;
	return n*fact(n-1);
}
int main() {
	int res = fact(3);
	cout << to_string(res) << endl;
}