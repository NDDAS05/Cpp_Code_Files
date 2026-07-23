// See copy for logic

class BSTIterator {
    stack<TreeNode*> stk;
    TreeNode* ptr = nullptr;
public:
    BSTIterator(TreeNode* root):ptr(root) {
        // Just inorder iterative logic.
        while(ptr!=nullptr){
            // Going to extreme left by pushing everything to the stack
            // 7--3--2--1
            stk.push(ptr);
            ptr = ptr->left;
        }
    }
    
    int next() {
        // This pops the top. Returns its value. Then pushes everything in stack by going extreme left starting from stack.tops right.
        if(stk.empty()) return INT_MAX;// Just for fun not needed.

        ptr = stk.top();
        stk.pop();

        if(ptr->right){
            TreeNode* right  = ptr->right;
            while(right!=nullptr){
                // Going to extreme left by pushing everything to the stack
                // 7--3--2--1
                stk.push(right);
                right = right->left;
            }
        }

        return ptr->val;
    }
    
    bool hasNext() {
        return !(stk.empty());
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */