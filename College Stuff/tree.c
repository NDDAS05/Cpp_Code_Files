#include<stdio.h>
#include<stdlib.h>

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

void free_BST(treenode* t) //Using postorder travarsal
{
	if(t==NULL)
		return;

	free_BST(t->lchild);
	free_BST(t->rchild);
	free(t);
}

int main()
{
	int op, val;
	treenode* root=NULL;

	printf("=======================\nAssignment: 5, Question 1\n=======================\n");

	while(1)
	{
		printf("\t1. Check if the tree is empty\n\t2. Insert a node in BST\n\t3. Check the number of available nodes\n\t4. Traverse the tree (Inorder)\n\t5. Traverse the tree (Preorder)\n\t6. Traverse the tree (Postorder)\n\t7. Free BST and exit\n\n");

		printf("Choice: ");
		scanf("%d",&op);

		switch(op)
		{
			case 1: if(isEmpty(root))
						printf("Tree is empty.\n");
					
					else 
						printf("Tree is not empty. Availale number of nodes: %d\n",getCount(root));

					break;

			case 2: printf("Enter value to insert: ");
					scanf("%d",&val);

					root=insertNode(root, val);

					printf("%d is inserted in the tree.\n",val);
					break;

			case 3: printf("The available number of nodes: %d\n\n",getCount(root));
					break;

			case 4: if(isEmpty(root))
					{
						printf("Tree empty.\n");
						break;
					}

					inorder(root);
					printf("\n");
					break;

			case 5: if(isEmpty(root))
					{
						printf("Tree empty.\n");
						break;
					}
			
					preorder(root);
					printf("\n");
					break;
			case 6: if(isEmpty(root))
					{
						printf("Tree empty.\n");
						break;
					}
			
					postorder(root);
					printf("\n");
					break;

			case 7: printf("\n\nFreeing Tree.\n\n");
					free_BST(root);
					exit(1);
					
			default:printf("Choose valid option.\n");
		}
	}

	return 0;
}
