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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr;
        ListNode* nextNode = nullptr;
        ListNode* currentNode = head;

        while(currentNode != nullptr){
            // send next first
            nextNode = currentNode->next;

            // atp 0<----0<----prevNode    currentNode--->0(nextNode)---->0
            // link current to prev. Connection will be lost with nextNode
            currentNode->next = prevNode;

            // Now list is:0<----0<----prevNode<----currentNode     (nextNode)---->0
            prevNode = currentNode;
            currentNode = nextNode;

            // atp 0<----0<----prevNode    (currentNode & nextNode)---->0
        }

        return prevNode;
    }
};