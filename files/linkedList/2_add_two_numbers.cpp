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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* sum=nullptr, *list1=l1, *list2=l2, *sumTail =nullptr;
        
        //creating dummy node
        sum = new ListNode(0);
        sumTail=sum;
        int carry=0, currentSum=0;
        
        while(list1!=nullptr || list2!=nullptr){
            
            currentSum = ((list1)?(list1->val):0) + ((list2)?(list2->val):0)+carry;
            
            // carry is res of dividing
            carry = currentSum/10;
            
            // sum is remainder
            currentSum = currentSum%10;
            sumTail->next = new ListNode(currentSum);
            sumTail=sumTail->next;
            if(list1)list1=list1->next;
            if(list2)list2=list2->next;
        }
        
        if(!list1 && !list2 && carry==1){
            //Extra 1 as carry
            sumTail->next=new ListNode(1);
            // no need to move sumtail anymore
        }
        
        //Hoping leetcode internal garbage collector works!!
        
        sum=sum->next;
        return sum;
    }
};