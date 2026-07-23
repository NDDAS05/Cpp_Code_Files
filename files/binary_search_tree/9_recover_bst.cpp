class Solution {
    TreeNode* violation1=nullptr; // If adjacent, v1 is the prev, v2 is 1st violated, v3 will be nullptr
    TreeNode* violation2=nullptr;
    TreeNode* prev=nullptr; 
    // Keeping track of previous node.

    // If v1 null, we set the prev of violated to v1(1 9 3: prev is 9 curr is 3. Violation 1 at prev 9) and probabable violated current to v2.

    // If v1 is not null and again violation found, set the current Violated to v2. V1 holds the last violated

    void inorder(TreeNode* root){
        if(root==nullptr) return;

        // inOrder: go left
        inorder(root->left);

        // Process current node
        if(prev!=nullptr && prev->val > root->val){
            if(violation1==nullptr){
                // that means this is the first violation
                violation1 = prev;
                violation2 = root;
            }
            else{
                // violation1 is not null means the swapped were not adjacent
                // So this 2nd violated will be v2 now. V1 already holds last violated. That is the node for which next is smaller than current.
                violation2 = root;
            }
        }

        // set up prev node.
        prev = root;

        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        std::swap(violation1->val, violation2->val);
    }
};