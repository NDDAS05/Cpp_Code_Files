class Solution {
    int getHeight(TreeNode* root){
        if(!root) return -1; // 1 node height 0, no node height -1
        int count = 0;

        while(root->left!=nullptr){
            root=root->left;
            count++;
        }

        return count;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        // First check left and right height.

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // these heights are considering root->left and right are at 0 heights.
        // So 2^(h+1) -1 stands becase root is already excluded.

        if(leftHeight == rightHeight){
            // right May be not perfect but left is.
            return (1<<(leftHeight+1))-1 + 1 + countNodes(root->right);
        } // +1 for root

        // - has higher precedence than <<. So, 1<<(h+1)-1 will be parsed as 1<<(h+1-1)
        // so extra bracket.

        else{
            // leftheight must be greater than right as nodes are filled from left. 
            // In that case, right subtree is perfect but left subtree is complete.
            return (1<<(rightHeight+1))-1 + 1 + countNodes(root->left);

        }

    }
};