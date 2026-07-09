/*
 *
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
    void traversal(TreeNode* root, int curr_lvl, int curr_depth, int& min_lvl,
                   int& max_lvl, unordered_map<int, vector<pair<int,int>>>& ump) {
        if (root == nullptr)
            return;

        min_lvl = std::min(min_lvl, curr_lvl);
        max_lvl = std::max(max_lvl, curr_lvl);
        pair<int, int> p = {curr_depth, root->val};

        ump[curr_lvl].push_back(p);
        traversal(root->left, curr_lvl - 1, curr_depth + 1, min_lvl, max_lvl,
                  ump);
        traversal(root->right, curr_lvl + 1, curr_depth + 1, min_lvl, max_lvl,
                  ump);
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map < int, vector<pair<int, int>>> ump;
        int min_lvl = 0;
        int max_lvl = 0;
        traversal(root, 0, 0, min_lvl, max_lvl, ump);

        for (int i = min_lvl; i <= max_lvl; i++) {
            auto& vec = ump[i];
            sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
                if (a.first == b.first)
                    return a.second < b.second;
                return a.first < b.first;
            });
            
            vector<int> vect;
            for (auto& i : ump[i]) {
                vect.push_back(i.second);
            }

            ans.push_back(vect);
        }
        return ans;
    }
};