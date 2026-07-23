 // Logic: All the values on the left must be smaller than root
 // All on right must be greater than root.
 // Simple recursion won't work as we need to track like:
 //           5
 //       4        6 
 //             3     7
 //
 // This is invalid cuz 3<5 but on right of 5. It will pass as 6(3 7) satisfies BTREE property locally. So we need a "RANGE OF VALUES for true false checking" not simple greater than less than root

// long used as question says node value would be entire int range.
// So INTMIN INTMAX are valid values.

class Solution {
    bool checkBST(TreeNode* root, long minAllowed, long maxAllowed){
        if(!root) return true;

        // since for every node we are sending node range information, we do not need to check with thier root.

        if((root->val) >= maxAllowed || (root->val) <= minAllowed) return false;

        return checkBST(root->left, minAllowed, root->val) && checkBST(root->right, root->val, maxAllowed);

    }
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root, LONG_MIN, LONG_MAX); //long min/max is a thing
    }
};