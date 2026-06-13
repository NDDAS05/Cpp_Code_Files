class Solution {
	public:
	
	void insertAtBottom(int elem, stack<int>& st){
	    if(st.empty()) {
	        st.push(elem);
	        return;
	    }
	    
	    int st_top = st.top();
	    st.pop();
	    // Reursively insert in the remaining stack
	    insertAtBottom(elem, st);
	    
	    st.push(st_top);
	}
	void reverseStack(stack<int> &st) {
		// code here
		// How to reverse a stack?
		// Pop the stack elements, store them in a new stack!
		
		// That is what we will be doing with recursion. Every step holds top data, pops stack once and finally when the stack empty,
		// fills one by one.
		
		// Base case: Only 1 ele: just push it.
		// Recursive step: We pop the top element. Hope god pops ALL remaining element, we will just push it in the empty stack!
		if (st.empty())
			return;
		
		int stack_top = st.top();
		st.pop();
		
		reverseStack(st);
// 		st.push(stack_top); This does not work because stack->revStack->stack again gives us same stack.
        
        insertAtBottom(stack_top, st);
		
	}
};
