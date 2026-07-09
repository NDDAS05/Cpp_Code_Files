class Solution {
    void preOrder(Node* root, vector<int> path, vector<vector<int>>& ans){
        if(root == nullptr) return;
        // DO not push ans at this null checking because for a node whose left and right both are null, this part will be true 2 times (when called via root->left and again when called via root->right... on both cases current root == null so same vector will be pushed twice.)
        // Not sure if this above check is needed or not...
        
        path.push_back(root->data);
        if(root->left == nullptr && root->right == nullptr) { // If current node is leaf, push the path and return.
            ans.push_back(path);
            return;
        }
        preOrder(root->left, path, ans);
        preOrder(root->right, path, ans);
    }
  public:
    vector<vector<int>> Paths(Node* root) {
        
        // Using pre-order traversal
        vector<vector<int>> ans;
        vector<int> path;
        
        preOrder(root, path, ans);
        
        return ans;
    }
};