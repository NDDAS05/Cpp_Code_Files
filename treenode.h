#ifndef TREE_H
#define TREE_H

#include<stddef.h>

typedef struct node{

        int data;
        struct node* lchild;
        struct node* rchild;
        struct node* parent;

}treenode;

int isEmpty(treenode* t);
treenode* insertNode(treenode* t, int val);
int getCount(treenode* t);
int inorder(treenode* t);
int preorder(treenode* t);
int postorder(treenode* t);
void free_BST(treenode* t);

#endif
