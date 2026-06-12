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

    void reverse(ListNode* start, ListNode* end){
        ListNode* prev = nullptr;
        ListNode* curr = start;
        ListNode* next = nullptr;

        while(prev!=end){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int num;
        ListNode* tailmark=head;
        ListNode* start=head, *end=head;

        num=k-1;
        // 1. Manually reverse the first group
        while(num--){
            end=end->next;
            if(end==nullptr) return head;
        }
        ListNode* nextPtr = end->next;
        reverse(start, end);
        head = end;
        tailmark = start;
        tailmark->next = nextPtr;

        while(nextPtr){
            num = k-1;
            start=nextPtr;
            end = nextPtr;
            while(num--){
                end=end->next;
                if(end == nullptr) return head;
            }

            nextPtr = end->next;
            reverse(start, end);
            tailmark->next = end;
            tailmark = start;
            tailmark->next = nextPtr;
        }

        return head;
    }
};