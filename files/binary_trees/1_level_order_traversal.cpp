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

 // Store elements level wise in queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        if(!root) return {};

        queue<TreeNode*> q;

        if(root) q.push(root);

        while(!q.empty()){
            // for every node pushed in q, we will be pushing their left-rights to the q. So make sure that we actually record the number of records are in q in current level so that we do not end up processing entire tree at the root node itself.
            int currentSize = q.size();
            vector<int> currLevel;

            for(int i=0; i<currentSize;i++){
                TreeNode* t = q.front();
                q.pop();
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);

                currLevel.push_back(t->val);

            }

            ans.push_back(currLevel);
        }
        return ans;
    }
};