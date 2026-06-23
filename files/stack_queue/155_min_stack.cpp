// bellow is first mine own approach
// Current is actually not required as we are storing the "highest current min" in min_current.
// Instead of min_current directly use min_till_top's last element as the min_current.

class MinStack {
    stack<int> s;
    vector<int> min_till_top;
    int min_current;
public:
    MinStack():min_current(INT_MAX) {
        // given get min is always called on empty stack.
    }
    
    void push(int value) {
        s.push(value);
        // Current till top is stored in min current.
        // while pushing, min_current stores the minimum till now.
        min_current = std::min(value, min_current);
        min_till_top.push_back(min_current);
    }
    
    void pop() {
        // Popping from stack, popping from min_till_top after the last removal as well.
        s.pop();
        min_till_top.pop_back();
        // Here updating min_current to set to the updated current that can be found from min_till_top array
        // Here if the stack goes empty (last element popped), this array will be empty too. so .size() - 1 will be min_till_top[-1] which will be undefined. Handlle this edge case separately.
        if(min_till_top.empty()) min_current = INT_MAX;
        else
            min_current = min_till_top[min_till_top.size() -1];
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_till_top[min_till_top.size() -1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */