// Mine: not optimal

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

// Remember the recursive way

// if(node == null) return; // Basically do nothing and pop the stack
/*
    if(not null){
        --recursive call (pushing in stack) to root->left
    
    // After node becomes null:
    
        -- stack call ends with node=null conditon, root->left frame is popped from stack.
        --print current node
        -- recursive call (pushing in stack) to root->right
        --this also ends in node=null condition which pops the stack frame.
    
    } -- end of program -> stack frame goes empty.
    
    We will trace the exact same steps but iteratively.
*/

class Solution {
  public:
    vector<int> inOrder(Node* root) {
        if(!root) return {};
        
        vector<int> inorder;
        
        stack<Node*>stk;
        Node* currNode = root;
        
        currNode = currNode->left;
        
        stk.push(root);
        
        while(!stk.empty() || currNode){ // if stack is empty, also currnode(stack's left or right child) is also empty, we reached the end. If it was a right skewed, stack would be empty but currNode would be pointing to roots right child
            // above cond: if either stack has elements or current node is not null
            if(currNode!=nullptr){
                // We go to left node
                // Pushing the current frame into stack
                stk.push(currNode);
                currNode = currNode->left;
            }
            else{// After the left call becomes null, THEN the if(node==null) recursive call and subsequent current node printing and pushing right node happened.
            
                // as per recursive code, we encountered if(node==null)
                // It returned: so we do not push anything.
                
                // Now we printed the current node: ie. the node at the top of stack
                // Then we made a recursive call to right node
                inorder.push_back(stk.top()->data);
                currNode = stk.top()->right;
                
                stk.pop(); // This pop: in recursive, after going to right and returning, we popped both the right frame (during return) and top(after return)
                // here we processed the node. We don't need it anymore. So we pop it.
                
                
                // note: we set up the currnode to right here.
                // if stack is empty (root of entire tree processed), and righted currnode is also empty, our traversal is done
            }
        }
        return inorder;
    }
};





//=====proper======


#include <bits/stdc++.h>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
// Function to perform inorder traversal
// of a binary tree iteratively
vector<int> inorder(TreeNode* root){
    // Initialize a stack to track nodes
    stack<TreeNode*> st;
    // Start from the root node
    TreeNode* node = root;
    // Initialize a vector to store
    // inorder traversal result
    vector<int> inorder;

    // Start an infinite
    // loop for traversal
    while(true){
        // If the current node is not NULL
        if(node != NULL){
            // Push the current
            // node to the stack
            st.push(node);
            // Move to the left child
            // of the current node
            node = node->left;
        }
        else{
            // If the stack is empty,
            // break the loop
            if(st.empty()){
                break;
            }
            // Retrieve a node from the stack
            node = st.top();
            // Remove the node from the stack
            st.pop();
            // Add the node's value to
            // the inorder traversal list
            inorder.push_back(node->data);
            // Move to the right child
            // of the current node
            node = node->right;
        }
    }
    // Return the inorder
    // traversal result
    return inorder;
}

};

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the inorder traversal
    vector<int> result = sol.inorder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

