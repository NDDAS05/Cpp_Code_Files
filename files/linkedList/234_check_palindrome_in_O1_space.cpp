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

    ListNode* findMid(ListNode* head){
        ListNode* fast = head, *slow=head;

        while(fast!=nullptr && fast->next!=nullptr){
            fast = fast ->next->next;
            slow=slow->next;
        }
        // for odd, mid node.
        // For even, n/2 +1  th node (1 based)
        return slow;
    }

    ListNode* reverse(ListNode* head){
        //  This gets the new head
        ListNode* prev= nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;

        while(current!=nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid = findMid(head);
        ListNode* revHead = reverse(mid);
        ListNode* ptr1 = head, *ptr2=revHead;
        bool ans=true;

        while(ptr2!=nullptr){
            if(ptr1->val != ptr2->val)  ans=false;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        reverse(revHead);
        return ans;
    }
};