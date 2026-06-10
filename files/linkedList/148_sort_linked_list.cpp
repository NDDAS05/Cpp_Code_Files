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

// Translating Merge Sort into Linked List version

class Solution {
public:
    // Trying Merge Sort: Not 0(1) space because of recursive stack space.
    ListNode* findMid(ListNode* head) {
        ListNode* prev_to_mid = nullptr;
        ListNode *slow = head, *fast = head;

        // No need to check for 1 or 0 nodes- they will be handled in the
        // sortList function.
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev_to_mid = slow;
            slow = slow->next;
        }

        prev_to_mid->next = nullptr;
        return slow;
    }

    ListNode* mergeList(ListNode* head, ListNode* mid) {
        // It will have two list NULL TERMINATED as done in find mid function.
        // Gonna modify head and mid directly.

        ListNode *mergeHead = nullptr, *mergeTail = nullptr;

        // Set up for first node
        if (head->val > mid->val) {
            mergeHead = mid;
            mergeTail = mid;
            mid = mid->next;
            mergeTail->next = nullptr;
        } else {
            mergeHead = head;
            mergeTail = head;
            head = head->next;
            mergeTail->next = nullptr;
        }
        // For rest of the nodes
        while (head != nullptr && mid != nullptr) {
            if (head->val > mid->val) {
                mergeTail->next= mid;
                mid = mid->next;
                mergeTail = mergeTail->next;
                mergeTail->next = nullptr;

            } else {
                mergeTail->next = head;
                head=head->next;
                mergeTail = mergeTail->next;
                mergeTail->next = nullptr;
            }
        }

        if(head!=nullptr){
            mergeTail->next = head;
        }
        else{
            mergeTail->next = mid;
        }

        return mergeHead;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr) return head;
        else if(head->next == nullptr) return head;
        else{
            ListNode* mid = findMid(head);

            head = sortList(head);
            mid= sortList(mid);

            return mergeList(head, mid);
        }
    }
};