#include<iostream>
#include<algorithm>
using namespace std;
int main(int argc, char const *argv[]) {
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int a_size = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<a_size; i++) { cout << arr[i] << " "; } cout << endl;
    // sort(arr, arr+a_size);
    // sort(arr, arr+a_size, greater<int>()); //sorting in descending order
    sort(arr+2, arr+a_size); //sort from third element till the end of array
    for(int i=0; i<a_size; i++) { cout << arr[i] << " "; } cout << endl;
    return 0;
}