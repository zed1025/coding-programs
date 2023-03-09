// https://www.interviewbit.com/problems/max-non-negative-subarray/
#include<bits/stdc++.h>
using namespace std;
vector<int> solution(vector<int> A) {
	long long max_so_far=0, max=0;
    vector<int> msf, max1;
    for(int i=0; i<A.size(); i++) {
        if(A[i] >= 0) {
            max_so_far += A[i];
            msf.push_back(A[i]);
            if (max_so_far == 0 && msf.size() > max1.size()) {
            	max1 = msf;
            }
            if (max_so_far > max) {
                max = max_so_far;
                max1 = msf;
            }
        } else {
            msf.clear();
            max_so_far = 0;
        }
    }
    return max1;
}
int main() {
	// vector<int> input = { 0, 0, -1, 0 };
	vector<int> input = {1967513926, 1540383426, -1303455736, -521595368};
	vector<int> output = solution(input);
	for(auto it: output) {
		cout << it << " ";
	} cout << endl;
}