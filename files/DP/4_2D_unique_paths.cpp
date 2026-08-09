class Solution {
    int pathCount(int i, int j, vector<vector<int>>& dp){
        // base case: 1. Source node
        if(i == 0 && j==0){
            dp[0][0] = 1;
            return dp[0][0];
        }
        // if found in DP return that
        // (should have checked if out of bound index but that will be done before making recursive call: this is because starting is never invalid 0,0)
        else if(dp[i][j]!=0) return dp[i][j];

        else{
            int upCell_ways = (i-1<0) ? 0 : pathCount(i-1, j, dp);
            int leftCell_ways = (j-1 < 0) ? 0 : pathCount(i, j-1, dp);
            
            return dp[i][j] = upCell_ways + leftCell_ways;
        }
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // A node can only be visited through its above and its left side.
        // Unique path to current node(i,j) = up(i, j-1) + up(i-1, j);
        // Since we can visit a node in many many ways, we can store the values in dp once we compute them.

        return pathCount(m-1, n-1, dp);
    }
};