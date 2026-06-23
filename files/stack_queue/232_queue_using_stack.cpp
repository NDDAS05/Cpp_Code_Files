class MyQueue {
    std::stack<int> s1;
    std::stack<int> s2;
public:
    MyQueue() {
        // :)
    }
    
    void push(int x) {
        // We only push in stack s1.
        s1.push(x);
    }
    
    int pop() {
        int top;
        // here comes the trick.
        // First queue-fy the stack.
        // That is if the s2 is empty, pop s1 elements store in s2: which will store elements in reversed order.

        // This stack s2's top is og queue's front.
        if(!s2.empty()){
            top = s2.top();
            s2.pop();
            return top;
        }

        //if empty
        while(!s1.empty()){
            top = s1.top();
            s1.pop();
            s2.push(top);
        }
        top = s2.top();
        s2.pop();
        return top;
        

    }
    
    int peek() {
        // This time also we need to "queue-fy" the stack.
        if(!s2.empty()) return s2.top();

        while(!s1.empty()){
            int top = s1.top();
            s1.pop();
            s2.push(top);
        }
        return s2.top();
    }
    
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */