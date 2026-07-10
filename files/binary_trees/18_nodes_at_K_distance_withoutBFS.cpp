



 // unordered_set.count(x) returns 1 if exists (cuz set only holds unique element so if something exists count will be one)

class Solution {
    // first construct a parent pointer link.
    // May be use hash map as all elements are confirmed to be distinct

    // This function will return pointer to target and in the meantime fill the hashmap with parent links
    TreeNode* fillMap(TreeNode* root, unordered_map<int, TreeNode*>& ump, int target){
        if(root==nullptr) return nullptr;
        TreeNode* targetPtr=nullptr;

        //doing level order traversal to fill out ump
        // Ump contains parent of each node
        queue<TreeNode*> q;
        q.push(root);
        ump[root->val] = nullptr; // Root does not have a parent.

        while(!q.empty()){
            int currSize = q.size();
            for(int i=0; i<currSize; i++){
                TreeNode* t = q.front();
                if(t->val == target) targetPtr = t;
                q.pop();

                if(t->left){ 
                    q.push(t->left);
                    ump[t->left->val] = t;
                }

                if(t->right){
                    q.push(t->right);
                    ump[t->right->val] = t;
                }
            }
        }

        return targetPtr;
    }

    void traversal(TreeNode* root, int nodesRem, vector<int>& ans, unordered_map<int, TreeNode*>& ump, unordered_set<int>& visited){
        if(root==nullptr) return;
        if(nodesRem == 0) {ans.push_back(root->val);  return;}

        // Otherwise
        // Now from the given node, traverse in all directions

        // If parent exists go in that direction
        visited.insert(root->val);

        // ump[root->val] gives parent pointer
        // ump[root->val]->val gives parent value
        if(ump[root->val] != nullptr && visited.count(ump[root->val]->val)==0) // parent pointer found
        {
            traversal(ump[root->val], nodesRem-1, ans, ump, visited);
        }

        if(root->left && visited.count(root->left->val)==0) traversal(root->left, nodesRem-1, ans, ump, visited);
        if(root->right && visited.count(root->right->val)==0) traversal(root->right, nodesRem - 1, ans, ump, visited);
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<int, TreeNode*> ump;
        TreeNode* targetPtr = fillMap(root, ump, target->val);
        vector<int> ans;
        unordered_set<int> visited;

        traversal(targetPtr, k, ans, ump, visited);

        return ans;

    }
};