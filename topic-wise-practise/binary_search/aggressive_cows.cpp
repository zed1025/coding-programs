/**
https://www.codingninjas.com/codestudio/problems/aggressive-cows_1082559
*/

#include<bits/stdc++.h>
using namespace std;

//functions
bool isPossibleSolution(vector<int> &arr, int k, int mid) {
    sort(arr.begin(), arr.end());
    int cowsCount = 1;
    int lastPos = arr[0]; 

    for(int i=0; i<arr.size(); i++) {
        if(arr[i]-lastPos >= mid) { //possible solution exists
            cowsCount++;
            if(cowsCount == k) {
                return true;
            }
            lastPos = arr[i];
        } 
    }
    return false;
}

int largestMinimumDistance(vector<int> &arr, int k) {
    int s = 0;
    int e = *max_element(arr.begin(), arr.end());
    int ans = -1;

    int mid = s + (e-s)/2;

    while(s<=e) {
        if(isPossibleSolution(arr, k, mid)) {
            ans = mid;
            s = mid+1; //since we want to find the "largest" minimum distance
        } else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}

int main() {
    vector<int> arr = {4,2,1,3,6};
    int k=2; //number of aggressive cows

    int ans = largestMinimumDistance(arr, k);

    cout << ans << endl;
    return 0;
}