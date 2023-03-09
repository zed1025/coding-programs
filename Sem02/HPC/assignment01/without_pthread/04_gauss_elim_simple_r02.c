#include<stdio.h>

void gaussElim_simple(int m, int n, double a[m][n]){
    int i,j,k;
    for(i=0;i<m-1;i++){
        for(k=i+1;k<m;k++){
            double  term=a[k][i]/a[i][i];
            for(j=0;j<n;j++){
                a[k][j]=a[k][j]-term*a[i][j];
            }
        }
    }
}

void read_matrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%lf",&matrix[i][j]);
        }
    } 
}

void print_matrix(int m, int n, double matrix[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%lf\t",matrix[i][j]);
        }
        printf("\n");
    } 
}

void copy_matrix(int m, int n, double matrix1[m][n], double matrix2[m][n]){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            matrix2[i][j]=matrix1[i][j];
        }
    } 
}
 
int main(){
    int m,n,i,j;
    printf("Enter the size of the matrix:\nNo. of rows (m)\n");
    scanf("%d",&m);
    printf("No.of columns (n)\n");
    scanf("%d",&n);
    //Declare a matrix to store the user given matrix
    double a[m][n];
    //Declare another matrix to store the resultant matrix obtained after Gauss Elimination
    double U[m][n];
    printf("\nEnter the elements of matrix:\n");
    read_matrix(m,n,a);
    copy_matrix(m,n,a,U);
    //Perform Gauss Elimination 
    gaussElim_simple(m,n,U);
    printf("\nThe Upper Triangular matrix after Gauss Eliminiation is:\n\n");
    print_matrix(m,n,U);
    return 0;    
}