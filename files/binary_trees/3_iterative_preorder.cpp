/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        if(!root) return {};
        
        stack<Node*> stk;
        stk.push(root);
        
        vector<int> ans;
        
        // In recursive version, we processed (pop-print) current one
        // Then called left called right.
        
        // So in stack we push right first then left so that left remains on top and right is processed after left is processed.
        while(!stk.empty()){
            // process current one
            Node* currNode = stk.top();
            ans.push_back(currNode->data);
            stk.pop();
            
            // push RIGHT and left to stack
            if(currNode->right)stk.push(currNode->right);
            if(currNode->left)stk.push(currNode->left);
        }
        return ans;
    }
};