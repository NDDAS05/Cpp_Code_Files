/*
54. Spiral Matrix

Given an m x n matrix, return all elements of the matrix in spiral order.

(0,0) → → → → (0,3)
  ↑           ↓
(1,0)   → →   (1,3)
  ↑        ↓  ↓
(2,0)   ← ←   (2,3)
  ↑           ↓
(3,0) ← ← ← ← (3,3)


Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:


Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]


Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100


*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {

    int top_axis = 0;
    int bottom_axis = matrix.size() - 1;
    int right_axis = matrix[0].size() - 1;
    int left_axis = 0;

    int max_print = (matrix.size() * matrix[0].size());
    // Now margin shrinks by 1 after every complete side print.
    int i = 0;
    vector<int> vec;

    while (vec.size() < max_print) {
      // Printing along top axis. Going right.
      for (int i = left_axis; i <= right_axis && vec.size() < max_print; i++) {
        vec.push_back(matrix[top_axis][i]);
      }
      top_axis++;
      // Down
      for (int i = top_axis; i <= bottom_axis && vec.size() < max_print; i++)
        vec.push_back(matrix[i][right_axis]);
      right_axis--;

      // left
      for (int i = right_axis; i >= left_axis && vec.size() < max_print; i--)
        vec.push_back(matrix[bottom_axis][i]);
      bottom_axis--;

      // top ^
      for (int i = bottom_axis; i >= top_axis && vec.size() < max_print; i--)
        vec.push_back(matrix[i][left_axis]);
      left_axis++;
    }
    return vec;
  }
};

int main() {
  Solution s;
  vector<vector<int>> Matrix;
  Matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  vector<int> vec = s.spiralOrder(Matrix);
  for (int i : vec)
    cout << i << " --- ";
  cout << endl;

  return 0;
}
