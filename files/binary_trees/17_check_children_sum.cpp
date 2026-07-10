void changeTree(TreeNode* root){
    if(!root) return;

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    if(!left && !right) return; //do not do anything from leaf nodes.

    int leftData = (left)?left->data:0;
    int rightData = (right)?right->data:0;

    if(root->data >=leftData && root->data>= rightData){
        if(left) left->data = root->data;
        if(right) right->data = root->data;
    }

    // if atleast greater than one, root has scope to increase in future. Just recurse left and right
    changeTree(left);
    changeTree(right);

    root->data = ((left)?left->data:0) + ((right)?right->data:0);
}