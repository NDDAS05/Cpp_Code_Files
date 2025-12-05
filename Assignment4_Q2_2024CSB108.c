#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

typedef struct listNode
{
        int data;
        struct listNode* next;
}node;

node* addListNodeSorted(node* start, int elem)
{
        node* temp=NULL;
        temp=(node*)malloc(sizeof(node));
        if(temp==NULL)
        {
                printf("Memory allocation failed. Exiting program.\n");
                exit(1);
        }

        temp->data= elem;
        temp->next= NULL;

        if(start==NULL)
        {
                return temp;
        }

        node* ptr=start;

        if(elem > ptr->data)
        {
                temp->next = ptr;
                return temp;
        }

        node* prec=start;

        while(ptr!=NULL)
        {
                if(ptr->data < elem)
                {
                        prec->next = temp;
                        temp->next = ptr;
                        return start;
                }

                prec=ptr;
                ptr=ptr->next;
        }

        prec->next=temp;
        return start;
}




int isPresentListNodeSorted(node* start, int elem)
{
        node* ptr= start;
        int count=0;

        while(ptr!=NULL && (ptr->data >= elem))
        {
                count++;
                if(ptr->data == elem)
                {
                        return count;
                }
                ptr=ptr->next;
        }

        return count;
}

node* deleteListNodeSorted(node* start, int elem)
{
        if(start==NULL)
        {
                return NULL;
        }

        node* ptr= start;

        if(start->data == elem)
        {
                start=start->next;

                free(ptr);

                printf("Deleted %d.\n",elem);

                return start;
        }

        node* prev= start;

        while(ptr!=NULL)
        {
                if(ptr->data==elem)
                {
                        prev->next=ptr->next;
                        free(ptr);
                        printf("Deleted %d.\n",elem);
                        return start;
                }
                prev=ptr;
                ptr=ptr->next;
        }

        printf("Data not found.\n");
        return start;
}

void printLinkedList(node* start)
{
        if(start==NULL)
        {
                printf("NULL\n");
                return;
        }

        node* printPtr=start;

        printf("Start->");

        while(printPtr!=NULL)
        {
                printf(" %d ->",printPtr->data);
                printPtr=printPtr->next;
        }
        printf(" NULL\n");
}

//Functions for Question 2

void freeListNodeSorted(node* start)
{
        if(start==NULL)
        {
                exit(0);
        }
        
        node*ptr=start;

        while(ptr!=NULL)
        {
                start=start->next;
                free(ptr);
                ptr=start;
        }

}

void updateListNode(node* start)
{
    if(start==NULL)
    {
        printf("List does not exist.\n");
        return;
    }

    node* ptr=start;
    while(ptr!=NULL)
    {
        int random= rand()%10;
        ptr->data+=random;
        ptr=ptr->next;
    }
}

node* reverseListNodeSorted(node* start)
{
    if(start==NULL)
        return NULL;

    node* currNode=start;
    node* prevNode=NULL;
    node* nextNode=NULL;

    while(currNode!=NULL)
    {
        nextNode=currNode->next;
        currNode->next=prevNode;
        prevNode=currNode;
        currNode=nextNode;
    }
    
    return prevNode;
}


node* sortListNode(node* start)
{
    if (start==NULL || start->next==NULL)
    {
        return start;
    }

    node *current, *nextNode, *prev;
    int isSwapped;

    do
    {
        isSwapped=0;
        prev=NULL;
        current=start;

        while(current->next!=NULL)
        {
            nextNode=current->next;
            
            if(current->data < nextNode->data)
            {
                isSwapped=1;

                if(prev==NULL)
                {
                    current->next = nextNode->next;
                    nextNode->next = current;
                    start=nextNode;
                    prev=nextNode;
                }

                else
                {
                    prev->next=nextNode;
                    current->next = nextNode->next;
                    nextNode->next=current;
                    prev=nextNode;;   
                }
            }

            else
            {
                prev=current;
                current=current->next;
            }
        }
    } while(isSwapped);

    return start;
}

node* mergeListNodeSorted(node* start1, node* start2)
{
    if(start1==NULL)
        return start2;
    if(start2==NULL)
        return start1;

    node* result=NULL, *end=NULL;

    if(start1->data >= start2->data)
    {
        result = start1;
        start1=start1->next;
    }
    else
    {
        result=start2;
        start2=start2->next;
    }

    end=result;

    while(start1 && start2)
    {
        if(start1->data >= start2->data)
        {
            end->next=start1;
            start1=start1->next;
        }

        else
        {
            end->next=start2;
            start2=start2->next;
        }
        end=end->next;
    }

    if(start1)
        end->next=start1;
    else
        end->next=start2;


    start1=NULL;
    start2=NULL;

    return result;
}

int main()
{

        srand(time(NULL));

        node* head=NULL;
        node* head2=NULL;
        int element, rvalue, option;
        while(1){
            
         printf("\nEnter operation to perform: \n\n\t1. Add data to list\n\t2. Search for a data\n\t3. Remove a data from list\n\t4. Print the list.\n\t5. Update the list with random values.\n\t6. Reverse the list.\n\t7. Sort the list.\n\t8. Merge two lists.\n\t9. Exit\n\nEnter option: ");
         scanf("%d",&option);

         switch(option)
         {
                case 1: printf("Enter data to add: ");
                        scanf("%d", &element);

                        head=addListNodeSorted(head, element);
                        printf("Added %d successfully.\n",element);
                        break;

                case 2: printf("Enter data to search: ");
                        scanf("%d",&element);
                        rvalue=isPresentListNodeSorted(head, element);

                        if(rvalue==0)
                        {
                                printf("Data not found in the list.\n");
                                break;
                        }

                        printf("Data found at index: %d\n",rvalue);
                        break;

                case 3: printf("Enter data to delete: ");
                        scanf("%d",&element);

                        head=deleteListNodeSorted(head, element);
                        break;

                case 4: printf("Printng list:\n\t");
                        printLinkedList(head);
                        break;
                
                case 5: printf("Updating list with random values...\n");
                        updateListNode(head);
                        printLinkedList(head);
                        break;

                case 6: printf("Reversing the list...\n");
                        head = reverseListNodeSorted(head);
                        printLinkedList(head);
                        break;
                
                case 7: printf("Sorting the list...\n");
                        head = sortListNode(head);
                        printLinkedList(head);
                        break;

                case 8: printf("Create a second list for merging.\n");
                        printf("Enter data for list 2 (0 to stop):\n");
                        do {
                            printf("Enter data: ");
                            scanf("%d", &element);
                            if (element != 0) {
                                head2 = addListNodeSorted(head2, element);
                            }
                        } while (element != 0);
                        
                        printf("List 1:\n\t");
                        printLinkedList(head);
                        printf("List 2:\n\t");
                        printLinkedList(head2);

                        printf("Merging the two lists.\n");
                        head = mergeListNodeSorted(head, head2);
                        head2 = NULL;
                        printf("Merged list:\n\t");
                        printLinkedList(head);
                        break;
                
                case 9: printf("Exiting program.\n");
                        freeListNodeSorted(head);
                        exit(0);
                        
                default: printf("Enter valid option.\n");
        }
       }

       return 0;
}

