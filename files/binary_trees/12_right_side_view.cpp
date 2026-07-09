class Solution {
    
public:
    vector<int> rightSideView(TreeNode* root) {
        // Just keep the left most element at level order traversal
        // For left side view, just keep the firs element at every level in level order traversal
        queue<TreeNode*> q;
        vector<int> ans;

        if(root==nullptr) return {};
        q.push(root);

        while(!q.empty()){
            int currSize = q.size();
            
            for(int i=1; i<=currSize; i++){
                TreeNode* t = q.front();
                q.pop();

                if(i==currSize) ans.push_back(t->val);

                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return ans;
    }
};