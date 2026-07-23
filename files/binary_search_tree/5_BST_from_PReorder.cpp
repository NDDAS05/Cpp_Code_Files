BST from Preorder

Idea: Process preorder exactly once using an index and an upper bound.
Left subtree: values < root->val.
Right subtree: values < parent's upper bound.
Time: O(n)
Space: O(h)
'
class Solution {
    int idx = 0;

    TreeNode* build(vector<int>& preorder, int upperBound) {
        if (idx == preorder.size() || preorder[idx] > upperBound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[idx++]);

        root->left = build(preorder, root->val);
        root->right = build(preorder, upperBound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};



==============
Another O(n) solution

There's also an iterative solution using a stack.

Idea:

The stack stores the path from the root to the current node.
If the next value is smaller than the stack top, it is the left child.
Otherwise, keep popping until finding its parent; the new value becomes the right child of the last popped node.
==============

TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> st;
    st.push(root);

    for (int i = 1; i < preorder.size(); i++) {
        TreeNode* node = new TreeNode(preorder[i]);

        if (preorder[i] < st.top()->val) {
            st.top()->left = node;
        } else {
            TreeNode* parent = nullptr;
            while (!st.empty() && st.top()->val < preorder[i]) {
                parent = st.top();
                st.pop();
            }
            parent->right = node;
        }

        st.push(node);
    }

    return root;
}


// My soln derived from normal preorder to bst
// TC: O(n logn)
// SC O(n)


class Solution {
    int findLimit(vector<int>& preorder, int start, int end, int target){
        // find the last element smaller than current one;
        int ans=-1;

        while(start<=end){
            int mid = start + (end-start)/2;

            if(preorder[mid] < target){
                ans = mid;
                start=mid+1;
            }

            else{
                end = mid-1;
            }
        }

        return ans;
    }

    TreeNode* constructTree(vector<int>& preorder, int preStart, int preEnd){
        if(preStart>preEnd) return nullptr;

        TreeNode* newNode = new TreeNode(preorder[preStart]);

        int leftEnd = findLimit(preorder, preStart+1, preEnd, preorder[preStart]);
        if(leftEnd!=-1){
            newNode->left = constructTree(preorder, preStart+1, leftEnd);
        }
        else leftEnd = preStart;

        newNode->right = constructTree(preorder, leftEnd+1, preEnd);

        return newNode;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return constructTree(preorder, 0, preorder.size()-1);
    }
};