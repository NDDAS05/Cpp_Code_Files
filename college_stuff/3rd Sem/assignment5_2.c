#include<stdio.h>
#include<stdlib.h>
#include "treenode.h"

int height(treenode* t)
{
    if(t==NULL)
    {
        return -1;
    }

    else
    {
        int lheight= height(t->lchild);
        int rheight=height(t->rchild);

        return 1+((lheight>rheight)? lheight:rheight);
    }
}

int max(treenode* t)
{
    if(t!=NULL)
    {
        treenode* ptr=t;
        while(ptr->rchild !=NULL)
        {
            ptr=ptr->rchild;
        }

        return ptr->data;
    }
    
    printf("Tree is empty.\n");
    return 0;
}

int min(treenode* t)
{
    if(t!=NULL)
    {
        treenode* ptr=t;
        while(ptr->lchild !=NULL)
        {
            ptr=ptr->lchild;
        }

        return ptr->data;
    }
    printf("Tree is empty.\n");
    return 0;
}

int equal(treenode* t1, treenode* t2)
{
    if(t1==NULL || t2==NULL)
    {
        if(t1==t2) return 1; //equal

        else
            return 0;
    }

    else{
        if((t1->data == t2->data) && equal(t1->lchild,t2->lchild) && equal(t1->rchild, t2->rchild))
            return 1;
        
        return 0;
    }
}

treenode* insucc(treenode* t, int key)
{
    //First searching the "key" in the list
    treenode* ptr=t;

    while(ptr!=NULL)
    {
        if(ptr->data == key)
        {
            break;
        }
        else if(ptr->data < key)
        {
            ptr=ptr->rchild;
        }
        else
        {
            ptr=ptr->lchild;
        }
    }

    if(ptr==NULL)
    {
        return NULL;
    }

    ptr=ptr->rchild;

    while(ptr!=NULL && ptr->lchild!=NULL) //Since inorder successor means min of right subtree- which will be left-most element of right subtree of key
    {
        ptr=ptr->lchild;
    }
    return ptr;
}

int deleteNode(treenode **t, int val)
//Double pointer is used, because if BST has only 1 node and that is to be deleted, it is not possible to detect updated root-node in main() function as the return type is int.
{
    if(*t == NULL)
    {
        printf("BST does not exist.\n");
        return 0;
    }

    if(val < (*t)->data)
    {
        return deleteNode(&(*t)->lchild, val);
    }

    else if(val > (*t)->data)
    {
        return deleteNode(&(*t)->rchild, val);
    }

    else{ //Data found
        
        if((*t)->lchild==NULL)
        {
            treenode* temp=(*t);
            (*t)=(*t)->rchild;
            free(temp);
        }

        else if((*t)->rchild==NULL)
        {
            treenode* temp=(*t);
            (*t)=(*t)->lchild;
            free(temp);
        }
    }
}

int main()
{
    return 0;
}