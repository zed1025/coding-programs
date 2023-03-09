#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 
int max(int x, int y) { return (x > y)? x: y; } 

struct node 
{ 
    int data; 
    struct node *left, *right; 
};
struct farg{
    struct node * root;
    int minv;
}; 
  

void * MISS(void *arg) {  
    struct node *root=((struct farg*)arg)->root;
    
    if (root == NULL) 
       return 0; 
    pthread_t t1,t2,t3,t4,t5,t6;
    struct farg a1,a2,a3,a4,a5,a6;
    // Caculate size excluding the current node 
    a1.root=root->left;
    a2.root=root->right;
    pthread_create(&t1,NULL,MISS,(void *)&a1);
    pthread_create(&t2,NULL,MISS,(void *)&a2);
    int size_excl =a1.minv+a2.minv; 
   
    int size_incl = 1; 
    if (root->left){ 
        a3.root=root->left->left;
        a4.root=root->left->right;
        pthread_create(&t3,NULL,MISS,(void *)&a3);
        pthread_create(&t4,NULL,MISS,(void *)&a4);
    }

    if (root->right){
        a5.root=root->right->left;
        a6.root=root->right->right;
        pthread_create(&t5,NULL,MISS,(void *)&a5);
        pthread_create(&t6,NULL,MISS,(void *)&a6);
    }
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);  
    size_excl =a1.minv+a2.minv; 

    pthread_join(t3,NULL);
    pthread_join(t4,NULL);
    size_incl+=a3.minv+a4.minv;

    pthread_join(t5,NULL);
    pthread_join(t6,NULL);
    size_incl+=a5.minv+a6.minv;
    // Return the maximum of two sizes 
    ((struct farg *)arg)->minv= max(size_incl, size_excl); 
    return arg;
} 
  
  
// A utility function to create a node 
struct node* newNode( int data ){ 
    struct node* temp = (struct node *) malloc( sizeof(struct node) ); 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

int main() { 
    struct node *root         = newNode(20); 
    root->left                = newNode(8); 
    root->left->left          = newNode(4); 
    root->left->right         = newNode(12); 
    root->left->right->left   = newNode(10); 
    root->left->right->right  = newNode(14); 
    root->right               = newNode(22); 
    root->right->right        = newNode(25); 
    struct farg arg={root,0};
    MISS(&arg);
    printf ("Size of the Maximal Independent Set is %d ", arg.minv); 
  
    return 0; 
} 

