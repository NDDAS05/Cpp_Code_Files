// ========================
// This is the optimal1. There is another good soln available.
// Could have also done it using Hashmaps.
// Like storing the already visited node addresses while traversing one array.
// Then while traversing next one, check hash map for every single node.




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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // Approach: We need to make the two lists level.
        // So get the length of the two
        // Preadvance the larger one by the diff.
        // Now check one by one

        ListNode* longer, *shorter;
        ListNode* ptr1= headA;
        int count1 = 0, diff;
        while(ptr1!=nullptr) {
            count1++;
            ptr1=ptr1->next;
        }

        int count2=0;
        ptr1 = headB;
        while(ptr1!=nullptr) {
            count2++;
            ptr1=ptr1->next;
        }

        if(count1>count2){
            diff=count1-count2;
            ListNode* longer = headA;
            ListNode* shorter = headB;
        }

        else{
            diff=count2-count1;
            ListNode* longer = headB;
            ListNode* shorter = headA;
        }

        ptr1=longer;
        for(int i=1; i<=diff;i++){
            ptr1=ptr1->next;
        }
        ListNode* ptr2 = shorter;
        // That previous diff loop ensures remaining length is same for both of the list
        while(ptr1!=nullptr){
            if(ptr1 == ptr2) return ptr1;
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }

        return nullptr;
    }
};