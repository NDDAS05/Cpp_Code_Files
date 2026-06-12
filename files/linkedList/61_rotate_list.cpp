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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        ListNode* start = head;
        ListNode* end = head;
        
        // Finding list length
        int listLength = 0;
        while(end!=nullptr){
            listLength++;
            end = end->next;
        }
        end=head;
        k= k%listLength;
        if(!k) return head; // if 0 then return

        // We want one pointer before (k node grp) from end. its next = nullptr;
        // One pointer at the end -> end->next = head
        // One pointer at the start -> new head (technically not needed. cuz this will be start->next anyway)

        while(k--){
            end = end->next;
        }

        while(end->next!=nullptr){
            start = start->next;
            end = end->next;

            // Kinda a sliding window of fixed length. 
        }
        end->next = head;
        head = start->next;
        start->next = nullptr;

        return head;

    }
};