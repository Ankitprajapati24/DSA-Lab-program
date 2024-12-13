#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *lchild;
    struct Node *rchild;
};

void insert(struct Node **tree, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); 
    newNode->info = value;
    newNode->lchild = newNode->rchild = NULL;

   
    if (*tree == NULL) {
        *tree = newNode;
    }
    else {
        
        if (value < (*tree)->info) {
            insert(&(*tree)->lchild, value); 
        } else {
            insert(&(*tree)->rchild, value);
        }
    }
}

void inorder(struct Node *tree) {
    if (tree != NULL) {
        inorder(tree->lchild);      
        printf("%d ", tree->info);  
        inorder(tree->rchild);      
    }
}

int main() {
    struct Node *tree = NULL; 
    insert(&tree, 15);
    insert(&tree, 10);
    
    printf("The Tree : ");
    inorder(tree);
    printf("\n"); 
    return 0;
}

