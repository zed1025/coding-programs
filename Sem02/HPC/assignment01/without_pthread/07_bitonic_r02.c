#include <stdio.h>
#include <stdlib.h>
#define MAX 8
#define SWAP(x,y) t = x; x = y; y = t;
 
void compare();
void bitonic_merge(int, int, int);
void rec_bitonic(int, int, int);
void sort();
 
int data[MAX];
int up = 1;
int down = 0;
 
int main() {
    int i;
 
    printf("\nEnter the data(%d): ", MAX);
    for (i = 0;i < MAX ;i++) {
        scanf("%d", &data[i]);
    }
    sort();
    for (i = 0;i < MAX;i++) {
        printf("%d ", data[i]);
    }
}
/*
 * compare and swap based on dir
 */
void compare(int i, int j, int dir) {
    int t;
 
    if (dir == (data[i] > data[j])) {
        SWAP(data[i], data[j]);
    }
}
/*
 * Sorts a bitonic sequence in ascending order if dir=1
 * otherwise in descending order
 */
void bitonic_merge(int low, int c, int dir) {
    int k, i;
 
    if (c > 1) {
         k = c / 2;
        for (i = low;i < low+k ;i++)
            compare(i, i+k, dir);    
        bitonic_merge(low, k, dir);
        bitonic_merge(low+k, k, dir);    
    }
}
/*
 * Generates bitonic sequence by sorting recursively
 * two halves of the array in opposite sorting orders
 * bitonic_merge will merge the resultant data
 */
void rec_bitonic(int low, int c, int dir) {
    int k;
 
    if (c > 1) {
        k = c / 2;
        rec_bitonic(low, k, up);
        rec_bitonic(low + k, k, down);
        bitonic_merge(low, c, dir);
    }
}
 
/*
 * Sorts the entire array
 */
void sort() {
    rec_bitonic(0, MAX, up);
}