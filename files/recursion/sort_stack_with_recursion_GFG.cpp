#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void insert(int top, stack<int>& st){
        // Start reading from bottom code first.
        // At any given step, we can ONLY access the top. So, what can we do?
        
        // At first check if the stack is empty or our element is greater than the element
        // at the top of the stack. In that case, we can simply push our element on top of it

        // Also, this method is MUCH MUCH worse than taking all element in a vector and sorting vector directly. This is O(N^2) instead of O(n logn) we get in vector sorting.

        // This is only because of "stack operations only" constraints. Cuz storing in vector is not 
        // A stack operation.
        
        if(st.empty() || top >= st.top()){
            st.push(top);
            return;
        }
        
        
        // But if not, then we HOLD THE top in stk_top say, and hope that 
        // somehow god places our current element in remaining stack because,
        // We could not push it at the top.
        
        // This is just using recursion for the sake of it because we could easily make a
        // vector and keep on popping untill stack_top is <= our element to be pushed.
        
        // Instead of using vector space, we are using call stack space!
        
        int stk_top = st.top();
        st.pop(); // This returns void.
        insert(top, st);
        st.push(stk_top);
        return;
    }
    void sortStack(stack<int> &st) {
        
        if(st.empty()) return;
        // We solve it recursively.
        
        // First idea is obviously get an ele (only way is stack top access).
        // Hope God has sorted remainder of the stack.
        // Insert the element into the stack in its proper place.
        
        // Sorting is OK, how to insert? The withheld element may be placed at the middle
        // of the sorted stack. Then?
        
        // What we do is, instead of traversing it like array, we hold the elements in the
        // call stack instead.
        
        // Read bellow and go up :)
        
        int top = st.top();
        st.pop(); // pop returns void.. so can not be used directly.
        
        // Sort the remaining stack first
        sortStack(st);

        // Now insert current top we withheld.
        insert(top, st);
    }
};
