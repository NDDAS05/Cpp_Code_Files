// Implementing stack using queue.
// Here, queue uses FIFO but Stack uses lifo. 
// So, to simulate that, while inserting a new element, pop all existing that came before current one then push them at the back- in the same order.

// 1
// pop 1. Place 2. Place 1 -> 2-1 <stack top is also 2 if going by this order.
// pop 2[queue is fifo and 2 is in front]. pop 1. place 3. place 2. place 1: 3-2-1
// See, after push 1-2-3 stack would also be 3-2-1
class MyStack {
    std::queue<int> q;
public:
    MyStack() {
        // Nothing to initilalize here as q, by default provides its own start-end management    
    }
    
    void push(int x) {
        // Record size of queue before pushing 
        int size = q.size();
        // Push the new element
        q.push(x);
        while(size--){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        // Normal removal from queue, cuz queue is already stackified- ie stack top is q.front() too
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */