// For intuition first read main copy then follow up on this,

class Solution {
public:
    void flatten(TreeNode* root) {
        // Slightly modified morris.
        TreeNode* curr = root;
        if(!root) return;

        while(curr!=nullptr){
            // Find rightmost node of left subtree.
            // When in future left subtree is converted to linked list, that node will definitely be the last one as pre order traversal is root->left->right.
            // This last will definitely point to root->right's 1st node as that node marks end of the left subtree nodes.

            if(curr->left){
                TreeNode* rightMostOnLeft = curr->left;
                while(rightMostOnLeft->right) rightMostOnLeft = rightMostOnLeft->right;

                // Now connect the right most on left to root's right.
                rightMostOnLeft->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr; 
            }
            //move to right if left does not exist or after processing left nodes.

            curr = curr->right;
        }   
    }
};