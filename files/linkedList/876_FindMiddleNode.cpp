/*
876. Middle of the Linked List

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.
 

Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        // We can not determine the middle of a linked list without traversing it.
        // But since we have to travarse it anyway,
        // We can do this:
        // Middle node is AT the middle. IE: Half length of the list.
        // So, we use a pointer that travarses at double speed (ptr = ptr->next->next)
        // Another pointer that traverses half of our speedy pointers speed.
        // So when speedy pointer travarses the list, slow pointer is halfway.

        // A   B   C   D   E <odd node no>
        // p
        // dp

        //     p   dp
        //         p       dp (dp next is null)




        // Another case:

        // A    B    C    D
        // p
        //dp


        //      p(B)
        //           dp(C)

        //           p(C)
        //                     dp[itself null]


        // So what is the breaking condition?
        // When: if dp->next is not null. OR dp itself isn't null.


        ListNode* dp=head, *p=head;
        while(dp!=nullptr && dp->next!=nullptr){
            dp=dp->next->next;
            p=p->next;
        }

        return p;
    }
};