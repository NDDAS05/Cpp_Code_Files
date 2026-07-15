// For intuition and recursive stack trace look at Note Copy 

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root ==nullptr || root == p || root==q){
            return root; // If null we eliminate later.
            // p OR q as the question says that p q both exist.
        }

        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        if(leftLCA == nullptr) return rightLCA;
        if(rightLCA==nullptr) return leftLCA;
        return root;
    }
};