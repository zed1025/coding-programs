#include<bits/stdc++.h>
using namespace std;

//functions
//Good Solution
bool isPossible2(int *arr, int n, int m, int mid) {
    int studentCount = 1;
    int pageSum = 0;
    for(int i=0; i<n; i++) {
        if(pageSum+arr[i] <= mid) {
            pageSum += arr[i];
        } else {
            studentCount++;
            if(studentCount > m || arr[i] > mid) {
                return false;
            }
            pageSum = arr[i];
        }
        // uncomment if getting wrong answer
        // if(studentCount > m) {
        //     return false;
        // }
    }
    return true;
} 

//My Solution -> ERROR
bool isPossible(int *arr, int n, int m, int mid) {
    int sum=0, j=0, students=1;
    for(int i=0; i<n; i++) {
        sum = sum+arr[i];
        if(sum >= mid) {
            sum = arr[i];
            students++;
        }
    }
    if(students > m) {
        return false;
    }
    return true;
}

int bestAllocation(int *arr, int size, int m) {
    int s = 0;
    int e = 0;
    int n = size;
    for(int i=0; i<n; i++) {
        e = e + arr[i];
    }

    int mid = s+(e-s)/2;
    int ans=-1;

    while(s<=e) {
        if(isPossible2(arr, n, m, mid)) {
            ans = mid;
            e = mid-1;
        } else {
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main() {
    int arr[] = {10,20,30,40};
    int m = 2;
    int size = 4;

    int ans = bestAllocation(arr, size, m);

    cout << "Best Allocation: " << ans << endl;
    return 0;
}