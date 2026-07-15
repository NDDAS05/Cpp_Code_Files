/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

 // Just like preorder one but scanning from end as compared to start.

 
class Solution {
    TreeNode* build(vector<int>& inorder, int is, int ie,
                    vector<int>& postorder, int ps, int pe, unordered_map<int, int>& hm) {
        if (ps > pe || is > ie)
            return nullptr;

        // Last element in postorder is root
        TreeNode* root = new TreeNode(postorder[pe]);

        // Find root index in inorder
        int inRoot = hm[postorder[pe]];
        int numsLeft = inRoot - is;

        // Recursively build left and right subtrees
        root->left = build(inorder, is, inRoot - 1, postorder, ps,
                           ps + numsLeft - 1, hm);

        root->right = build(inorder, inRoot + 1, ie, postorder, ps + numsLeft,
                            pe - 1, hm);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> ump;
        for (int i = 0; i < inorder.size(); i++) {
            ump[inorder[i]] = i;
        }

        return build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, ump);
    }
};