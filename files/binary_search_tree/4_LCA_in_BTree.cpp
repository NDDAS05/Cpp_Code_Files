 // if p,q<root : CA in left sub tree
 // if p,q>root : CA in right sub tree
 // Otherwise, current one is the common ancestor.
 
 // as per constraints, pq WILL exist.

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != nullptr) {
            if (p->val < root->val && q->val < root->val) {
                root = root->left;  // both nodes lie in left subtree
            } else if (p->val > root->val && q->val > root->val) {
                root = root->right; // both nodes lie in right subtree
            } else {
                return root; // split occurs here, root is LCA
            }
        }
        return nullptr;
    }
};