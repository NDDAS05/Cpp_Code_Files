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

 // We want element in different/reversed order
 // For level order, we usually use "queue"
 // So here, to get "reversed order" "alternately", we shall use deque.

 // We shall maintain a "pop state"
 // When pop state is 0, we pop from front push from back
 // When pop state is 1, we pop from back and push from front

 // Do a dry-run... it works! x)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        deque<TreeNode*> dq;
        int popState=0;
        if(root) dq.push_back(root); 

        while(!dq.empty()){
            if(popState == 0){
                // At pop state 0, normal dq operation

                popState = 1;// Flipping state for operations of next iteration
                int curr_level_size = dq.size();
                vector<int> currLevelElements;

                for(int i=1; i<=curr_level_size; i++){
                    TreeNode* elem = dq.front();
                    dq.pop_front();
                    if(elem->left) dq.push_back(elem->left);
                    if(elem->right) dq.push_back(elem->right);
                    currLevelElements.push_back(elem->val);
                }
                ans.push_back(currLevelElements);
            }
            else{ // pop state 1. Do the reverse
                // At pop state 0, normal dq operation

                popState = 0;// Flipping state for operations of next iteration
                int curr_level_size = dq.size();
                vector<int> currLevelElements;

                for(int i=1; i<=curr_level_size; i++){
                    TreeNode* elem = dq.back();
                    dq.pop_back();
                    if(elem->right) dq.push_front(elem->right);
                    if(elem->left) dq.push_front(elem->left);
                    // Since we are pushing from front, but in next itr we want the left element at top/front, we need to push right first then left.

                    // If we did otherwise:    
                    // -->7(then pushed right) -->15(pushed first left) |9| -20->
                    currLevelElements.push_back(elem->val);
                }
                ans.push_back(currLevelElements);
            }
        }


        return ans;
    }
};






