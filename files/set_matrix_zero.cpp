// LC:73
/*
73. Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1
 

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    void setZeroes(vector<vector<int>>& matrix) {
        int width = matrix[0].size();
        int height = matrix.size();

        vector<bool> row_vec(height, false);
        vector<bool> col_vec(width , false);

        // Pass 1 : Mark Row/ Column to be executed

        for(int i = 0; i<height; i++)
        {
            for(int j = 0; j<width; j++)
            {
                if ( matrix[i][j] == 0 ) 
                {
                    row_vec[i] = true; col_vec[j] = true;
                }
            }
        }

        // Pass 2 : Execute 'em
        for(int i=0; i<height; i++)
        {
            if(row_vec[i]) {for( int p=0; p<width; p++ ) matrix[i][p] = 0; }
        }

        for(int i=0; i<width; i++)
        {
            if(col_vec[i]) {for( int p=0; p<height; p++ ) matrix[p][i] = 0; }
        }

    }
};