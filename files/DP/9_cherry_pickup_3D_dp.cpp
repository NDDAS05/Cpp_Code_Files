/*
1463. Cherry Pickup II

You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] 
represents the number of cherries that you can collect from the (i, j) cell.

You have two robots that can collect cherries for you:

Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of cherries collection using both robots by following the rules below:

From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the cherries.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.
 

Example 1:


Input: grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively.
Cherries taken by Robot #1, (3 + 2 + 5 + 2) = 12.
Cherries taken by Robot #2, (1 + 5 + 5 + 1) = 12.
Total of cherries: 12 + 12 = 24.

=========================
Topic: < DP > < Recursion >

DP state:
Given r1 starts from 0, r2 starts from colSize-1 position.
We use a recursive function that directly gives us the result. 
Rec func: If robo1 pics cell_a, robo_b picks cell_b of current row_r, then max possible value = cell_a value + cell_b value + max_of_row_r+1(recursive)
Now since each robo can move /|\ in these dir, we need nested loop of directions to test all combinations: that is recursive call happens INSIDE nested for loops. 
If both of them lands in the same cell, one will pick 0 another will pick that cell cherry. So then rec func becomes: current_val + max_of_row_r+1(recursive);

Since we are picking max cherry count: out of bounds cases will return INT_MIN so they are neglected by max(). 

For the last row, out of bound row returns 0 with NO FURTHER REC CALLS. So both robo pick 0 cherries.

Where does DP come in?
==============================

We start from top, and gradually go to bottom. Then calculation starts from bottom when rec returns 0, moves up.
Without DP, every upper state(say 5-->curr row) will make recursive calls to the lower states( upto row 9-->max no of rows say) again and again. this will happen for every row. 
Last row makes i*j call. Last-1 row makes i*j+(calls made by last row). Last-2 makes i*j +calls made by Last-1 row, so on... (i*j because calls are in nested for loop)

<
 i: dir -1 0 1
 j: dir -1 0 1

 So 9 combinations
>

With dp we just check the dp array. So every step (that is at every row) AT MOST i*j recursive call is made to the lower row (higher by row value means lower row here)
DP array is filled gradually. At last lvl, last lvl content is filled. At last-1, we return last row contents for every call and fill last-1 row of dp array.


What each DP state indicate:
==============================
- Given current row r
- Given current pos of robo r1
- Given current pos of robo r2

-- What is the maximum amount of cherry that can be collected by robo1 and robo2 from the rows [r,  grid.size()-1] (From current to last row inclusive).
*/

class Solution {
    int maxCollect(int row, 
                   int r1_pos, 
                   int r2_pos, 
                   vector<vector<vector<int>>>& dp,
                   vector<vector<int>>& grid){
        
        int maxRow = grid.size();
        int maxCol = grid[0].size();

        if(row>=maxRow) return 0;

        if(r1_pos<0 || r1_pos >= maxCol || r2_pos<0 || r2_pos >= maxCol){
            return INT_MIN;
        }

        // dp array is used while backtracking from the base case.
        if(dp[row][r1_pos][r2_pos] != -1){
            return dp[row][r1_pos][r2_pos];
        }

        // Not found in DP. All subsequent cases will fill the DP array before returning.
        int val = 0;
        if(r1_pos == r2_pos){
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    val = max(val, maxCollect(row+1, r1_pos+i, r2_pos+j, dp, grid));
                }
            }
            return dp[row][r1_pos][r2_pos] = grid[row][r1_pos] + val;
        }

        // both different

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                val = max(val, maxCollect(row+1, r1_pos+i, r2_pos+j, dp, grid));
            }
        }
        return dp[row][r1_pos][r2_pos] = grid[row][r1_pos] + grid[row][r2_pos] + val;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // We use DP[row][robo1_col_pos][robo2_col_pos]
        // All 3 are needed to describe the state. 
        // Cherry at level i = current level cherry + solve(lower level cherry)--> recursive call<atp check dp array first then rec call>

        int row = grid.size(); int col = grid[0].size();

        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, vector<int>(col, -1)));
        return maxCollect(0, 0, col-1, dp, grid);
    }
};