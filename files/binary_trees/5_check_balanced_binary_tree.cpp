/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 // Check if right-left subtree are balanced or not. If they are, then only check for current ones.

class Solution {
    int calcHeight(TreeNode* root){
        if(root == nullptr) return 0;
        return (1+std::max(calcHeight(root->left), calcHeight(root->right)));
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        
        if(isBalanced(root->left) && isBalanced(root->right)){
            int leftHeight = calcHeight(root->left);
            int rightHeight = calcHeight(root->right);

            if(std::abs(leftHeight - rightHeight) <= 1) return true;
        }

        return false; // Either subtree height diff >1 or any one of the nodes are hight imbalanced.
    }
};