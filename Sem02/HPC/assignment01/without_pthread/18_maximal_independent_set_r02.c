#include <stdio.h>
#include <stdlib.h>

int max(int x, int y) { return (x > y) ? x : y; }

struct node {
    int data;
    int liss;
    struct node *left, *right;
};

int MIS(struct node *root) {
    if (root == NULL)
        return 0;

    if (root->liss)
        return root->liss;

    if (root->left == NULL && root->right == NULL)
        return (root->liss = 1);

    
    int liss_excl = MIS(root->left) + MIS(root->right);

    
    int liss_incl = 1;
    if (root->left)
        liss_incl += MIS(root->left->left) + MIS(root->left->right);
    if (root->right)
        liss_incl += MIS(root->right->left) + MIS(root->right->right);

    
    root->liss = max(liss_incl, liss_excl);

    return root->liss;
}


struct node *newNode(int data) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->liss = 0;
    return temp;
}


int main() {
    struct node *root = newNode(20);
    root->left = newNode(8);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);
    root->right = newNode(22);
    root->right->right = newNode(25);

    printf("Size of the Largest Independent Set is %d ", MIS(root));

    return 0;
}