/*
118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above
it as shown:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
.........
Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]


Constraints:

1 <= numRows <= 30
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pascal;
    pascal.push_back({1});
    if (numRows == 1)
      return pascal;
    pascal.push_back({1, 1});
    if (numRows == 2)
      return pascal;

    // numRows >2 AND row 0 and 1 are filled up.
    numRows -= 2;
    int i = 2;
    while (numRows--) {
      pascal.push_back({1});
      for (int itr = 0; itr < pascal[i - 1].size() - 1; itr++) {
        pascal[i].push_back(pascal[i - 1][itr] + pascal[i - 1][itr + 1]);
      }
      pascal[i].push_back(1);
      i++;
    }
    return pascal;
  }
};
