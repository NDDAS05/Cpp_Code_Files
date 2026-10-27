// 1277. Count Square Submatrices with All Ones
// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.

/*
   < Recursion > < 2D unpotimized DP> < 1D optimized DP >

We need to traverse such a way that we do not get same square multiple times.

So, we make start of each square unique. That is we use a dp array like: 
dp[i][j] : (i,j) is the starting position of the square. It stores how many squares are possible that starts from here.


How to find?
==================================
Starting at (i,j) we have to look at the squares made by ->(i,j+1), \(i+1, j+1),
|(i+1, j).( Downward arrow: | :)

So for
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]

We look at this
[
  [0, 1,  1*,     1*     ],
  [1, 1^, 1* ' ^, 1* '   ],
  [0, 1^, 1' ^,   1'     ]
 (Group of 1s marked by *, marked by ', marked by ^)

  There can be several cases:
  1. For all the adj (- \ |) 1s, starting from a adj 1, all have same number of squares. Then Starting from current 1, number of squares are: 1(solo current 1)+ number of squares for any of adj neighbour.

  (Remember: DP state is number of sqr starting at i,j. So for a cube of 3/3, for 0,0: number of squares(starting at 0,0) =3 (1 itself + for each adj possible =2))

  2. At least one of the adj has different number of formable square: Then, 1(self) + min of adj squares
  1 1 1 1 ->for left: 3, for bottom 3, for diagonal:2; SO possible 1+min(2,3,3)=3
  1 1 1 1
  1 1 1 1
  1 1 1 0

  3. At least 1 direct adj is 0(or out of bounds). Then its 1. Only for the current 1.
   
]


In this case we need to add all the dp array value after everything end as every place in dp array is a distinct square start.
*/

class Solution {
    int solve(vector<vector<int>>& dp, vector<vector<int>>& matrix, int row, int col){
        // 1. Out of range values: return 0
        // 2. Found in DP: return from DP
        // 3. Value 0: return 0
        // 4. Not in DP: calculate right, bottom, diag squares. Check equal or not. Accordingly update DP and return.
        int rowMax = dp.size();
        int colMax = dp[0].size();

        if(row<0 || row>=rowMax || col<0 || col>=colMax) return 0;

        if(dp[row][col]!= -1) return dp[row][col];
        if(matrix[row][col] == 0) return dp[row][col] = 0;

        int left = solve(dp, matrix, row, col+1);
        int bottom = solve(dp, matrix, row+1, col);
        int diagonal = solve(dp, matrix, row+1, col+1);

        if(left == 0 || bottom == 0 || diagonal == 0){
            return dp[row][col] = 1;
        }

        return dp[row][col] = 1+ min(left, min(bottom, diagonal));
    }
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                solve(dp, matrix, i, j);
            }
        }

        int sum = 0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(dp[i][j]!=-1) sum+=dp[i][j];
            }
        }

        return sum;

    }
};