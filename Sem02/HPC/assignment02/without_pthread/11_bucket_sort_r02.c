#include <stdio.h>
 
/* Function for bucket sort */
void bucket_sort(int array[], int n) {  
    printf("hello\n\n");
    int i, j;  
    int count[n]; 
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }
 
    for (i = 0; i < n; i++) {
        (count[array[i]])++;
    }
 
    for (i = 0, j = 0; i < n; i++)  {
        for(; count[i] > 0; count[i]--) {
            array[j++] = i;
        }
    }
}   
/* End of bucket_sort() */
 
/* The main() begins */
int main() {
    int array[100], i, num; 
 
    printf("Number of elements: ");   
    scanf("%d", &num);   
    printf("Enter %d elements:\n",num); 
    for (i = 0; i < num; i++)
        scanf("%d", &array[i]); 
    printf("\nElements before sorting : \n");
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);  
    printf("\nElements after sorting : \n"); 
    bucket_sort(array, num); 
    for (i = 0; i < num; i++)
        printf("%d ", array[i]);   
    printf("\n");     
    return 0;
}