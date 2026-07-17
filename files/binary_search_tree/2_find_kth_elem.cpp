// Inorder always prints element in sorted order.
// So the kth element printed must be the kth smallest in binary search tree.
// So for a "inorder traversal" all we need is to modify the part where we print the node. Just set the kth smallest to that (if that is the kth printed) element being printed instead.

// For more optimized soln, use morris traversal that eliminates stack space too.
// A true O(1) space soln.

// Bellow is NOT morris, just basic traversal.


class Solution {
    void findElem(TreeNode* root, int k, int& printedNo, int& kth){
        //inorder traversal
        if(root==nullptr) return;

        findElem(root->left, k, printedNo, kth);
        // for current elem calc
        printedNo++;
        if(printedNo == k) {
            kth = root->val;
            return;
        }

        findElem(root->right, k, printedNo, kth);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int printedNo = 0;
        int kth = INT_MIN;

        findElem(root, k, printedNo, kth);
        return kth;
    }
};