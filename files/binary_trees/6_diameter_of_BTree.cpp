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
class Solution {
    int maxPath(TreeNode* root, int& maxLength){
        // maxLength stores the max path length found so far.
        if(root==nullptr) return 0;

        int leftHeight = maxPath(root->left, maxLength);
        int rightHeight = maxPath(root->right, maxLength);

        maxLength = std::max(maxLength, leftHeight+rightHeight);
        // why? a -- b -- (root) -- c -- d
        // left subtree height =2, right height 2. sum 4.
        // now path length is also: a--b--root--c--d= 4 (5 nodes , 4 connectors)

        return (1+std::max(leftHeight, rightHeight));
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       // Idea is to- for every node find the max depth of left sub-tree and right subtree. Sum them do NOT do +1 (no of node -1 = no of edges i.e. diameter)

       int maxLength = INT_MIN;
       maxPath(root, maxLength);

       return maxLength;
    }
};