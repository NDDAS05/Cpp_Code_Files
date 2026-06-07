// Check my copy for Detailed breakdown of the algorithm
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // One way is to keep a map of visited nodes, linearly scan the array.
        // What about constant space way?

        ListNode* slow=head, *fast=head;

        while(fast && fast->next){
            slow=slow->next;
            fast = fast->next->next;

            if(slow==fast){
                // They met.
                //ListNode* ptr1 = head;
                // Using fast as ptr1 instead
                fast = head;
                //ListNode* ptr2=slow;
                // using slow as ptr2 instead
                while(fast!=slow){
                    fast=fast->next;
                    slow=slow->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};