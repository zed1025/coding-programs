#include<bits/stdc++.h>
using namespace std;

void sayDigits(int n) {
    const char* nums[10];
    nums[0] = "Zero";
    nums[1] = "One";
    nums[2] = "Two";
    nums[3] = "Three";
    nums[4] = "Four";
    nums[5] = "Five";
    nums[6] = "Six";
    nums[7] = "Seven";
    nums[8] = "Eight";
    nums[9] = "Nine";
    //base case
    if(n == 0)
        return;

    //recursion
    sayDigits(n/10);

    //processing
    int x = n%10;
    cout << nums[x] << " ";
}

int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    sayDigits(n);

    return 0;
}