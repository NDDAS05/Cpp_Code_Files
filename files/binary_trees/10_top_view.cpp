// Just like the vertical order traversal

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

// Idea: create vertical level wise map just like vertical travarsal.
// Only include the first element of the same level. Rest at "deeper depth" will be shadowed by the ones that are at "lesser depth"


class Solution {
    void preOrder(Node* root, int curr_lvl, int curr_depth,int& min_lvl, int& max_lvl, unordered_map<int, pair<int,int>>& ump){
        if(root==nullptr) return;
        
        min_lvl = min(min_lvl, curr_lvl);
        max_lvl = max(max_lvl, curr_lvl);
        
        if(ump.find(curr_lvl) == ump.end()){
            // could not find the curr_lvl key, so insert
            ump[curr_lvl] = {root->data, curr_depth};
        }
        else if(ump[curr_lvl].second > curr_depth){
            // the found elements depth is greater than mine one
            ump[curr_lvl] = {root->data, curr_depth};
        }
        preOrder(root->left, curr_lvl-1, curr_depth+1, min_lvl, max_lvl, ump);
        preOrder(root->right, curr_lvl+1, curr_depth+1,min_lvl, max_lvl, ump);
    }
  public:
    vector<int> topView(Node *root) {
        unordered_map<int, pair<int,int>> ump;
        vector<int> ans;
        
        int min_lvl = 0, max_lvl=0;
        preOrder(root, 0, 0, min_lvl, max_lvl, ump);
        
        for(int i=min_lvl; i<=max_lvl; i++){
            ans.push_back(ump[i].first);
        }
        
        return ans;
    }
};