#include<stdio.h>
#include<stdlib.h>

typedef struct node{

        int data;
        struct node* lchild;
        struct node* rchild;
        struct node* parent;

}treenode;

treenode* insertNode(treenode* t, int val)
{
        treenode* temp=(treenode*)malloc(sizeof(treenode));
        if(temp==NULL)
        {
                printf("Error occured. Exiting program.\n");
                return NULL;

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

void free_BST(treenode* t)
{
	if(t==NULL)
		return;

	free_BST(t->lchild);
	free_BST(t->rchild);
	free(t);
}

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
        if(t1==t2) 
        	return 1;

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
    treenode* ptr=t;
    treenode* inorder=NULL;

    while(ptr!=NULL)
    {
        if(ptr->data > key)
        {
            inorder=ptr;
            ptr=ptr->lchild; //If right child for the node containing the key does not exist, its parent will be its inorder successor
        }
        else if(ptr->data < key)
        {
            ptr=ptr->rchild;
        }
        else
        {
            if(ptr->rchild!=NULL) //If right subtree exists then minimum of right sub tree.
            {
            	treenode* temp=ptr->rchild;
            	while(temp->lchild!=NULL)
            	{
            		temp=temp->lchild;
            	}
            	inorder=temp;
            }

            return inorder; //No right child exists- in which case inorder successor is already found above.
        }
    }
    return NULL;
}

treenode* deleteNode(treenode *t, int val, int* del)
{
    if(t == NULL)
    {
    	return NULL;
    }

    else if(val < t->data)
    {
        t->lchild=deleteNode(t->lchild, val,del);
    }

    else if(val > t->data)
    {
        t->rchild=deleteNode(t->rchild, val,del);
    }

    else{

    	*del=1;
        
        if(t->lchild==NULL)
        {
            treenode* temp=t->rchild;
            free(t);
            return temp;
        }

        else if(t->rchild==NULL)
        {
            treenode* temp=t->lchild;
            free(t);
            return temp;
        }

        treenode* temp=insucc(t,val);
        t->data=temp->data;
        t->rchild=deleteNode(t->rchild,temp->data,del);
    }
    return t;
}

int main()
{
	int op,choice, val, del=0;
	treenode* root1= NULL;
	treenode* root2= NULL;

	printf("=========================\n    Assignment- 5, Question 2\n=========================\n");
	printf("\nChoose option \n");
	while(1)
	{
		printf("\n\n1. Enter data in BST\n2. Check current height of BST\n3. Get maximum data of BST \n4. Get minimum data of BST\n5. Check if two BST are equal\n6. Get inorder successor of a node \n7. Delete a node from BST\n8. Traverse BST(inorder)\n9. Free and exit\n");

		printf("\nEnter choice: ");
		scanf("%d",&op);

		switch(op){

			case 1: printf("Choose BST(1/2):");
					scanf("%d",&choice);
					printf("Enter data: ");
					scanf("%d",&val);

					if(choice==1)
					{
						root1=insertNode(root1, val);
						if(root1==NULL)
						{
							printf("Allocation failed. Try again.\n");
							break;
						}
					}

					else if(choice==2)
					{
						root2=insertNode(root2, val);
						if(root2==NULL)
						{
							printf("Allocation failed. Try again.\n");
							break;
						}						
					}

					else
						printf("Enter valid choice.");
					break;

			case 2: printf("Choose BST(1/2):");
					scanf("%d",&choice);
					if(choice==1)
					{
						printf("%d\n",height(root1));
					}

					else if(choice==2)
					{
						printf("%d\n",height(root2));
					}

					else
						printf("Enter valid choice.");
					break;

			case 3: printf("Choose BST(1/2):");
					scanf("%d",&choice);
					if(choice==1)
					{
						printf("%d\n",max(root1));
					}
			
					else if(choice==2)
					{
						printf("%d\n",max(root2));
					}
			
					else
						printf("Enter valid choice.\n");
					break;

			case 4: printf("Choose BST(1/2):");
					scanf("%d",&choice);
					if(choice==1)
					{
						printf("%d\n",min(root1));
					}
			
					else if(choice==2)
					{
						printf("%d\n",min(root2));
					}
			
					else
						printf("Enter valid choice.");
					break;

			case 5: if(equal(root1, root2))
					{
						printf("Two BSTs are euqal.\n");
					}

					else
						printf("Two BSTs are not equal.\n");

					break;

			case 6: printf("Choose BST(1/2):");
					scanf("%d",&choice);
					printf("Enter node value: ");
					scanf("%d",&val);

					if(choice==1)
					{
						treenode* temp=insucc(root1, val);
						if(temp==NULL)
						{
							printf("Node does not exist.\n");
							break;
						}

						printf("Inorder Successor of %d is: %d\n\n",val, temp->data);
						break;
					}

					else if(choice==2)
					{
						treenode* temp=insucc(root2, val);
						if(temp==NULL)
						{
							printf("Node does not exist.\n");
							break;
						}

						printf("Inorder Successor of %d is: %d\n\n",val, temp->data);
						break;						
					}

					else
						printf("Enter valid choice.");
					break;

			case 7: printf("Choose BST(1/2): ");
					scanf("%d",&choice);
					printf("Enter value to delete: ");
					scanf("%d",&val);

					if(choice==1)
					{
						root1=deleteNode(root1, val, &del);

						if(del==1)
							printf("Value %d deleted from BST.\n",val);
						
						else
							printf("Data not found in BST.\n");
					}

					else if(choice==2)
					{
						root2=deleteNode(root2, val, &del);

						if(del==1)
							printf("Value %d deleted from BST.\n",val);
						
						else
							printf("Data not found in BST.\n");

					}

					else
						printf("Enter valid choice.\n");
					break;
					
			case 8: printf("Choose BST to traverse(1/2):");
					scanf("%d",&choice);

					if(choice==1)
					{
						if(!inorder(root1))
						{
							printf("BST is empty. \n");
						}
						else 
							break;
					}

					else if(choice==2)
					{
						if(!inorder(root2))
						{
							printf("BST is empty. \n");
						}
						else 
							break;
					}

					else{
						printf("Enter valid choice.\n");
						break;
					}

			case 9: printf("Freeing BST.....\n");
					free_BST(root1);
					free_BST(root2);

					printf("Exiting program.\n");
					exit(0);
			default:printf("Enter valid choice. \n\n");	
		}
	}
	return 0;
}
