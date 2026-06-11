/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/


// Let them meet in cycle.
// If they do, use one of `em as a marker.
// Start a count there and increment slow (fast is marker say)
// When they meet again return that count.

// If they never met in the first place, return 0. No loops exist.


class Solution {
  public:
    int lengthOfLoop(Node *head) {
        Node* slow = head, *fast= head;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast ->next->next;
            
            if(slow==fast){//They met
            
                int count = 1;
                slow=slow->next;
                while(slow!=fast){
                    slow=slow->next;
                    count++;
                }
                return count;
            }
        }
        
        return 0;
    }
};