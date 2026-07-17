Floor: max value not exceeding x. xxxxxxx(val)  -------
Ceil: min value not lesser than x. --------  (val)xxxxx

class Solution {
  public:
    int findMaxFork(Node* root, int k) {
        // code here
        int res = -1;
        while(root!=nullptr){
            // Just like binary search.
            // xxxxxxxxx7 .........
            // If in xxx7 region store in ans and move right.
            // if in .... region just moe left
            if(root->data == k) return k;
            else if(root->data < k){
                res = root->data;
                root=root->right; // move right
            }
            else{
                root=root->left;
            }
        }
        
        return res;
    }
};