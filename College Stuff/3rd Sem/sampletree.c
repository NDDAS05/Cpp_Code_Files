#include<stdio.h>
#include<stdlib.h>
#include "treenode.h"

typedef struct node{

        int data;
        struct node* lchild;
        struct node* rchild;
        struct node* parent;

}treenode;

int isEmpty(treenode* t)
{
        if(t==NULL)
        {
                return 1;
        }

        return 0;
}

treenode* insertNode(treenode* t, int val)
{
        treenode* temp=(treenode*)malloc(sizeof(treenode));
        if(temp==NULL)
        {
                printf("Error occured. Exiting program.\n");
                exit(1);

        }
        temp->data=val;
        temp->lchild=temp->rchild=temp->parent=NULL;

        if(t==NULL)
        {
        	return temp;
        }

        treenode* ptr=t;
        while(1)
        {
                if(val<ptr->data)
                {
                        if(ptr->lchild==NULL)
                        {
                                ptr->lchild=temp;
                                temp->parent=ptr;
                                break;
                        }

                        ptr=ptr->lchild;
                }

                else if(val > ptr->data)
                {
                        if(ptr->rchild==NULL)
                        {
                                ptr->rchild=temp;
                                temp->parent=ptr;
                                break;
                        }

                        ptr=ptr->rchild;
                }
        }

        return t;
}

int getCount(treenode* t)
{
        if(isEmpty(t))
                return 0;

        else{
                return 1+getCount(t->lchild)+getCount(t->rchild);
        }
}

int inorder(treenode* t)
{
        if(t==NULL)
        {
                return 0;
        }

        inorder(t->lchild);
        printf("%d  ",t->data);
        inorder(t->rchild);

        return 1;
}


int preorder(treenode* t)
{
        if(t==NULL)
        {
                return 0;
        }

        printf("%d  ",t->data);
        preorder(t->lchild);
        preorder(t->rchild);

        return 1;
}

int postorder(treenode* t)
{
        if(t==NULL)
        {
                return 0;
        }

        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d  ",t->data);

        return 1;
}

void free_BST(treenode* t)
{
	if(t==NULL)
		return;

	free_BST(t->lchild);
	free_BST(t->rchild);
	free(t);
}
