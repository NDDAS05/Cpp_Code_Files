/*
19. Remove Nth Node From End of List

Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:


Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
 

Constraints:

The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

Follow up: Could you do this in one pass?
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */



 /*
 
 Approach:

To delete say 3rd node from end, we will use 2 pointers.
One (say a) will point at head, one (say b) will point at the NTH NODE FROM START.

Then we simultaneously increase a and b.

When b reaches end, a will automatically point to nth node from last!

Keep in mind, when "nth node from last" is head itself, we need to specially delete it.
For all other cases, we need to track its previous node to link it to current's next node after the deletion of the current node.


 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* ptr1=head, *ptr2=head, *prev_to_ptr1=nullptr;
        int node_diff = n-1;
        for(int i=0; i<node_diff; i++){
            ptr2=ptr2->next;
        }

        while(ptr2->next!=nullptr){
            prev_to_ptr1 = ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        //Removal
        if(ptr1 == head){
            // For heads, there is no Prev node.
            head=head->next;
            delete ptr1;
            return head;
        }
        prev_to_ptr1->next = ptr1->next;
        ptr1->next = nullptr;
        delete ptr1;

        return head;
    }
};