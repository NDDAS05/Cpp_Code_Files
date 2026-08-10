class Solution {
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp){
        // This recursion is for "Player 1".
        // What is the base case? if nothing remains in array (j<i)
        // Or only one element is in the array
        // i==j

        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];

        // Game strategy:
        // In my turn my best.
        // In enemy turn: their best i.e. my worst
        int take_ith = nums[i] + min(solve(i+2, j, nums, dp), solve(i+1, j-1, nums, dp));
        int take_jth = nums[j] + min(solve(i+1, j-1, nums, dp), solve(i, j-2, nums, dp));

        // My best
        return dp[i][j] = max(take_ith, take_jth);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));

        int totalPts = 0;
        for(auto i: nums){
            totalPts+=i;
        }

        int player1 = solve(0, nums.size()-1, nums, dp);
        totalPts -= player1;

        if(player1 >= totalPts) return true;
        return false;
    }
};