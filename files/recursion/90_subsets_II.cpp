class Solution {
public:
    void genSequence(vector<vector<int>>& ans, vector<int>& nums, vector<int>& seq, int pos){
        ans.push_back(seq);

        for(int i=pos; i<nums.size(); i++){
            // Make unique branches AND only include first occurence.
            if(i>pos && nums[i-1] == nums[i]) continue;

            seq.push_back(nums[i]);
            genSequence(ans, nums, seq, i+1);
            seq.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> seq;
        sort(nums.begin(), nums.end());
        genSequence(ans, nums, seq, 0);
        return ans;
    }
};