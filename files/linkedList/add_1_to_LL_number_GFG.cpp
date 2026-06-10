// Not the most optimal one pls look up


/* Structure of linked list Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    
    Node* reverseList(Node* head){
        Node* curr = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        
        
        while(curr!=nullptr){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    Node* addOne(Node* head) {
        head = reverseList(head);
        
        Node* ptr1 = head;
        Node* last = nullptr;
        int carry=1; // For 1st num, it is the +1, for rest it acts as carry
        
        while(ptr1!=nullptr){
            int data = ptr1->data;
            
            ptr1->data = (data + carry )%10;
            carry = (data + carry)/10;
            last = ptr1;
            ptr1 = ptr1->next;
        }
        
        if(!ptr1 && carry == 1){
            Node* newNode = new Node(1);
            last->next = newNode;
        }
        
        head = reverseList(head);
        return head;
    }
};