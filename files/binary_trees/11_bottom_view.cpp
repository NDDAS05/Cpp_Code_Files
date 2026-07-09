/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    struct nodes{
        Node* ptr;
        int vertical_lvl;
    };
    
    // Level order traversal
    // Since the bottom one (ones encountered later in lvl order traversal) are already at lower levels, they shadows the ones at same vertical level but pushed earlier(less deep).
    // Also, the question states for same vertical lvl same depth, later are selected, in this case that happens automatically cuz we are overwriting the earlier one at same v_lvl, whether that is at lesser depth or at same depth.
    
    
    void level_order(Node* root, int& min_lvl, int& max_lvl, unordered_map<int, int>& ump, queue<nodes>& q){
    
        q.push({root, 0});
        
        while(!q.empty()){
            int curr_size = q.size();
            while(curr_size--){ // This while is unnecessary because we do not need entire level at once. Insertion happens according to vertical depth which is already captured in min_lvl and max_lvl variables.
                nodes n = q.front();
                q.pop();
                
                ump[n.vertical_lvl] = n.ptr->data;
                min_lvl = std::min(min_lvl, n.vertical_lvl);
                max_lvl = std::max(max_lvl, n.vertical_lvl);
                
                if(n.ptr->left) q.push({n.ptr->left, n.vertical_lvl-1});
                if(n.ptr->right) q.push({n.ptr->right, n.vertical_lvl+1});
            }
        }
    }
    
    
  public:
    vector<int> bottomView(Node *root) {
        if(root==nullptr) return {};
        
        queue<nodes> q;
        vector<int> ans;
        unordered_map<int, int> ump;
        int min_lvl =0;
        int max_lvl =0;
        
        level_order(root, min_lvl, max_lvl, ump, q);
        
        for(int i=min_lvl; i<=max_lvl; i++){
            ans.push_back(ump[i]);
        }
        return ans;
        
    }
};