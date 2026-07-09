/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

// Just travarse in 3 parts: Left, Bottom, Right

class Solution {
  public:
    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;
        ans.push_back(root->data);
        if(root->left==nullptr && root->right == nullptr) return ans;
        stack<Node*>  stk;
        
        // But what if:
        /*
            2
                3
                    4
                5       6
                    8       7
                    
        In this case, it starts from "leaf" travarsal then going to right.
        So we split the tree in 3 parts: left(root->left is its root) Then leafs(starting from root itself) then right(root->right is its root)
        */
        
        
        Node* leftSubTree = root->left;
        Node* rightSubTree = root->right;
        
        if(leftSubTree!=nullptr){
            Node* ptr = leftSubTree;
            while(ptr->left!=nullptr || ptr->right!=nullptr){
                ans.push_back(ptr->data);
                
                if(ptr->left) ptr = ptr->left;
                else ptr=ptr->right;
            }
        }
        
        // This ends left travarsal.
        // Now leaf travarsal
        // Choose any form of travarsal: here preorder cz easy!!
        stk.push(root);
        while(!stk.empty()){
            Node* elem = stk.top();
            stk.pop();
            if(elem->left == nullptr && elem->right == nullptr) ans.push_back(elem->data); // only pushing leaf nodes
            if(elem->right) stk.push(elem->right);
            if(elem->left) stk.push(elem->left);
        }
        
        // Now right travarsal
        // My idea is to print in the reverse order of push.
        // SOOO,pushing the values may be in a stack/vector and printing in reverse order
        vector<int> right_travs;
        if(rightSubTree != nullptr){
            Node* ptr = rightSubTree;
            while(ptr->left!=nullptr || ptr->right!=nullptr){
                right_travs.push_back(ptr->data);
                if(ptr->right) ptr = ptr->right;
                else ptr=ptr->left;
            }
        }
        
        for(int i=right_travs.size()-1; i>=0; i--){
            ans.push_back(right_travs[i]);
        }
        
        return ans;
    }
};