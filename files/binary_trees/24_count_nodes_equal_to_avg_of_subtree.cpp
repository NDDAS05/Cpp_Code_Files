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
    pair<int, int> postorderTraversal(TreeNode* root, int& satisfied){
        // 1. Initialize counter to 1.
        // Each node visited will increment that counter to 1.
        // Return 1+returned total
        // the first int contains sum of values.
        if(root == nullptr) return {0, 0};

        auto [sumL, countLeft] = postorderTraversal(root->left, satisfied);
        auto [sumR, countRight] = postorderTraversal(root->right, satisfied);

        // for current node
        int totalSum = sumL + sumR + root->val;
        int totalCount = 1+countLeft+countRight;

        if(root->val == totalSum/totalCount) satisfied++;

        return {totalSum, totalCount};
    }
public:
    // needed: count of nodes and sum of subtree rooted at that node
    int averageOfSubtree(TreeNode* root) {
        int satisfied = 0;
        postorderTraversal(root, satisfied);

        return satisfied;
    }
};
