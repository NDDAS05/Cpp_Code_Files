/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

// We meet an element 2 times: when using it to call left, right
// Again when processing it after its left right are processed completely.

// My idea is, why not, while pushing in stack that i am pushing new node have not used it yet (node, 0)
// Then while using it to get left right, make it 1 and push right,0 and left,0

// So when checking top, if we see our current element is at top, we are pretty much sure that its left right are processed(thus not in stack above this one), so we can simply append it to our answer.



class Solution {
    struct nodeState{
        Node* ptr;
        bool isProcessed;
    };
  public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        
        stack<nodeState> stk;
        stk.push({root, false});
        
        while(!stk.empty()){
            // seeing if we processed the node or not
            if(stk.top().isProcessed == true){
                // We processed previously. So left right are already in place.
                ans.push_back(stk.top().ptr->data);
                stk.pop();
            }
            else{
                nodeState currTop = stk.top(); // marking true so that next time when we come back to this node, we see its left-right childs are already processed.
                
                // without completele popping and putting back, it was giving random errors.
                stk.pop();
                currTop.isProcessed = true;
                stk.push(currTop);
                
                if(currTop.ptr->right) stk.push({currTop.ptr->right, false});
                if(currTop.ptr->left) stk.push({currTop.ptr->left, false});
            }
        }
        
        return ans;
    }
};