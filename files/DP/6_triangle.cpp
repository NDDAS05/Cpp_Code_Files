// THE CHOSEN VALUE MUST BE OUTSIDE OF POSSIBLE VALUE RANGE
// In this problem -1 is a valid sum (0 00 000 0000 -1-1-1-1-1 -1-1-1-1-1-1 ..)
// That means the -1 marker will force multiple recursion.
// But absolute max value is 200 * 10000 = 2*10^6 which is lesser than INT_MAX.
// Using int_max as the marker instead.

class Solution {
    int triangleSum(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle){
        if(j>i || i<0 || j<0 || i>=triangle.size()) return 0;
        else if(dp[i][j] != INT_MAX) return dp[i][j];
        else if(i == triangle.size() -1){
            return dp[i][j] = triangle[i][j];
        }

        int leftPath = triangleSum(i+1, j+1, dp, triangle);
        int rightPath = triangleSum(i+1, j, dp, triangle);
        return dp[i][j] = triangle[i][j] + min(leftPath, rightPath);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int tSize = triangle.size();

        vector<vector<int>> dp(tSize);
        for(int i=1; i<=tSize; i++){
            dp[i-1] = vector<int>(i, INT_MAX);
        }

        return triangleSum(0, 0, dp, triangle);
    }
};