class Solution {
    bool preOrder(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr || root2 == nullptr){
            if(root1 == root2) return true;
            return false; // This or because if any one is nullptr can not access their value. So making sure both are strictly not nullptr.
        }
        else if (root1->val == root2->val){
            return preOrder(root1->left, root2->right) && preOrder(root1->right, root2->left);

            // r1->left == r2->right cuz mirrored about center (see example)
            //          1
            //      2        2
            //  3      4 4      3  <Note the mirroring: 2's left = other 2's right>
        }

        return false; // if values of two roots are not equal.
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr) return true;
        // Root is same.
        // So start from left and right side.
        // Then travarse both similarly together.
        // If both null or both has value same then true else false
        return preOrder(root->left, root->right);
    }
};