/*
Geek is attending a training program for n days. Each day he must perform exactly one of three activities: 
Running, Fighting, or Learning. 

Each activity earns a certain number of merit points, which can differ from day to day.
To improve all his skills, Geek cannot perform the same activity on two consecutive days.
Given a 2D matrix mat[][], where for the i-th day:

mat[i][0] is the merit points for Running
mat[i][1] is the merit points for Fighting
mat[i][2] is the merit points for Learning
Return the maximum total merit points Geek can earn over the n days.
*/

class Solution {
    public:
    int maximumPoints(vector<vector<int>>& mat) {
        // Using DP array
        // dp [lvl] [chosen]
        // Say: [2, 5, 3], [1, 7, 2], [1, 9, 3], [4, 1, 2]
        // dp: at [i][j]: At level i, if i choose j from the main array
        // then mx possible sum (dp[i-1][j+1,j+2] + mat[i][j]) : the max one. (j+1, j+2 are mod-ed)
        // [2, 5, 3]
        // [6(max(1+5, 1+3)), 10(max(7+2, 7+3)), 7(max(2+2, 2+5))]
        // [11, 16, 13]
        // [20, .., ..] : Ans is max of this row.
        
        int matSize = mat.size(); // i
        
        // vector<vector<int>> dp(matSize, vector<int>(3, -1));
        int max1=-1, max2=-1, max3=-1;
        
        for(int i=0; i<matSize; i++){
            if(i==0){
            //     for(int k=0; k<3; k++){
            //         dp[i][k] = mat[i][k];
            //     }
                max1 = mat[i][0];
                max2 = mat[i][1];
                max3 = mat[i][2];
            }
            else{
                // for(int k=0; k<3; k++){
                //     int maxPoint = max(dp[i-1][(k+1)%3], dp[i-1][(k+2)%3]);.... <incomplete>
                // }
                
                // Without the oldmax thing, modifying max1 in step 1 modifies max1 for max2 and 3 calc...
                int oldMax1 = max1;
                max1 = mat[i][0] + max(max2, max3);
                int oldMax2 = max2;
                max2 = mat[i][1] + max(oldMax1, max3);
                max3 = mat[i][2] + max(oldMax1, oldMax2);
            }
        }
        // now getting max of last dp row OR max of the max1-2-3
        return max(max(max1, max2), max3);
    }
};