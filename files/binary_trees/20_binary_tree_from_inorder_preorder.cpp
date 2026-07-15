/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


 // Recursively building sub tree.
 // look at the public function first then come back.

class Solution {
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& ump){
        // For root element, <just first iteration, nothing build yet> 
        // It preorder starts from current elements idx in preorder to the last of the array.
        // Now for left subtree:
        // Inorder starts from 0(inStart) to roots inorder index -1.
        // Pre order starts from root's preorder position+1 andd spans the number of elements that are on the left from root in inorder.

        // For right subtree:
        // Considerable inorder tree starts from roots inorder index + 1
        // Where it ends? Untill inEnd(last idx of inorder), because entire leftover part in inorder is part of right subtree (3) ->9<- (20, 15, 7)
        // About pre-order, since root-left-right, left elements are AFTER root. So we need to skip those left element too. if number of elements on left is 1(in inorder) and root index is say 1. 
        // Then preorder for right subtree is root(preStart)+numberOfElementsOnLeft+1(thats next) so 0+1+1=3. <remember this is on preorder treee. Root at inorder index 1 only gives us how many on left how many on right.
        // Root at 0 preorder index gives us the roots index here. So we skip root, left then start from last element on right.


        // During this entire process, inStart moves to inend for right subtree, inEnd moves to start for left subtree.
        // preStart only moves toward preEnd.
        // So base case can be when preStart>preEnd or inStart>inEnd
        // Why or? may be there are 0 node on left 99 nodes on right based on current root at 0 say.
        // So instart is 0. inEnd is root-1 that is 0 -1, instart>inend
        // but preStart is 1 and preEnd = 0.... well both holds!! :)
        // probably or is not necessary

        if(inStart>inEnd || preStart>preEnd) return nullptr;

        //root is at preStart.
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inorderRootIdx = ump[preorder[preStart]];

        // now need to do calc on how many on right of root.
        int onLeftElementNo = inorderRootIdx - inStart;

        // now we can recursively build left subtree.
        root->left = build(preorder, preStart+1, preStart+onLeftElementNo, inorder, inStart, inorderRootIdx-1, ump);

        root->right = build(preorder, preStart+onLeftElementNo+1, preEnd, inorder, inorderRootIdx+1, inEnd, ump);

        return root;


    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> ump;
        //building inorder map
        for(int i=0 ; i<inorder.size(); i++){
            ump[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, ump);
    }
};