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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> q;
        int maxWidth = 0;

        if(!root) return 0;
        q.push({root, 0});

        while(!q.empty()){
            long long firstIdx = 0;
            long long lastIdx = 0;

            // We use this offset value (the first ele idx at each level) to assign levels to childs of next level
//================================
// IMPORTANT
//================================

// Why normalization doesn't completely prevent overflow

// Suppose the tree is like this:

//         1
//       /   \
//      2     3
//     /       \
//    4         5
//   /           \
//  ...         ...

// At each level:

// Level 0:        0

// Level 1:      1      2

// Level 2:     3       6

// Level 3:     7      14

// Level 4:    15      30

// Now normalize.

// Level 4:

// indices: 15, 30

// offset = 15

// normalized:
// 0, 15

// Next level:

// children:
// 1, 32

// Normalize again:

// offset = 1

// 0, 31

// Notice something important:

// The difference between the leftmost and rightmost node keeps doubling every level.

// After 31 levels,

// normalized index ≈ 2^31

// which no longer fits inside a signed int.

// So although the absolute indices are reset every level, the width itself can still exceed INT_MAX.

            long long idx_offset = q.front().second;

            int currSize = q.size();
            for(int i=1; i<=currSize; i++){
                auto n= q.front();
                q.pop();

                long long currIdx = n.second - idx_offset;

                if(i==1) firstIdx =  currIdx;
                if(i==currSize) lastIdx = currIdx;

                if(n.first->left) q.push({n.first->left, 2*currIdx+1});
                if(n.first->right) q.push({n.first->right, 2*currIdx+2});
            }

            int width = (lastIdx-firstIdx+1);

            maxWidth = std::max(maxWidth, width);

            //          1: width 1 
            //      2       3 : width 2
            //    4   N   N   5 : width 4
        }

        return maxWidth;
    }
};