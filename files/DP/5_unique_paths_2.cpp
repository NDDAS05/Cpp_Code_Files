// -1 initialization helps to prevent recursive calls to "non obstacle" "unreachable states".

// Say
// . X . . <-- unreachable
// . X . . <-- unreachable
// . . . .
// . . . -

// Now, the top left are unreachable. But when our recursive call reaches there, it treates them as "not visited yet" and does recursive calls on 

// X . .
// X . .

// Cells aiming to count their ways to reach them by recursing on other top left unreachable cells.
// But -1 does not even allow recursive calls on those cells. So the entire X .. part is unvisited completely.
//     X .. 
class Solution {
    int countPath(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& obs){
        if(i<0 || j<0 || obs[i][j] == 1) return 0; // if either i<0 or j<0 is true skips to the return.
        else if(i == 0 && j==0 ){
            dp[i][j] = 1;
            return dp[i][j];
        }
        else if(dp[i][j]!=-1) return dp[i][j];
        else{
            return dp[i][j] = countPath(i-1, j, dp, obs)+ countPath(i, j-1, dp, obs);
        }
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        return countPath(m-1, n-1, dp, obstacleGrid);
    }
};