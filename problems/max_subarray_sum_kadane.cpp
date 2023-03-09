#include<bits/stdc++.h>
using namespace std;
int solution(vector<int> arr) { // kadane algorithm
	int sum=0, max=0;
	int begin_index=0, end_index=0;
	for(int i=0; i<arr.size(); i++) {
		sum += arr[i];
		if(sum > max) {
			max = sum;
		} 
		if(sum < 0) {
			sum = 0;
		}
	}
	return max;
}
int main() {
	vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
	cout << solution(arr);

}