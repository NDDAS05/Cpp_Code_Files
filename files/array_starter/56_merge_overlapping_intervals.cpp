#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> result;

    if (intervals.size() == 1) {
      result.push_back(intervals[0]);
      return result;
    }

    // First we need sorting the array based on their starting index VALUE
    // LESS GOO

    // Using custom iterator and lambda logic
    // Reference:
    // https://www.simplilearn.com/tutorials/cpp-tutorial/iterators-in-cpp

    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    // Intervals are now: 1-4   2-7    8-10    9-12
    // Merged intervals:  1-------7    8---------12
    // Logic: --------->    4 <=2        10 <= 9
    int i = 0;
    while (i <= intervals.size() - 1) {
      int j = i;

      while ((j + 1 < intervals.size()) &&
             (intervals[j][1] >= intervals[j + 1][0])) {
        j++;
      }

      // Now i at 1st arr, j at last arr.

      result.push_back({intervals[i][0], intervals[j][1]});
      i = j + 1;
    }
    return result;
  }
};
