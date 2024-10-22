#include <stdio.h>
#include <stdlib.h>

void insert(int );

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root, *parent, *current;

void preorder(struct node *temp){
    if (temp!=NULL){
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct node *temp){
    if(temp!=NULL){
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

void inorder(struct node *temp){
    if(temp!=NULL){
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

int main(){
    int a[]={27,14,11,45,15,78,98};
    int i;
    for(i=0; i<7; i++)
        insert (a[i]);

    printf("preorder :");
    preorder(root);
    printf("\npostorder :");
    postorder(root);
    printf("\ninorder :");
    inorder(root);

    return 0;
    
}

void insert(int no){
    struct node *temp;
    temp = malloc(sizeof(struct node));
    temp->data = no;
    temp->left = NULL;
    temp->right = NULL;

    if(root==NULL)
        root=temp;
    else{
        current=root;
        parent=NULL;
        while(1){
            parent=current;
            if(no < current->data){
                current=current->left;
                if(current==NULL){
                    parent->left=temp;
                    return;
                }
            }
            else{
                current=current->right;
                if(current==NULL){
                    parent->right=temp;
                return;
                }
            }
        }
    }
}




