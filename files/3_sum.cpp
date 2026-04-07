/*
15. 3Sum
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.



Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation:
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not
matter.


Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.


Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.


Constraints:

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {

    vector<vector<int>> result;
    std::sort(nums.begin(), nums.end());

    // Fix the first element as i. nums[j] + nums[k] has to be -nums[i]

    for (int i = 0; i < nums.size() - 2; i++) {
      // Skipping dupes.
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      // Setting j to be i+1, and k = n-1;
      int j = i + 1, k = nums.size() - 1;

      while (j < k) {
        int sum = nums[j] + nums[k];
        if (sum > (-nums[i])) { // Greater than target
          k--;
        } else if (sum < (-nums[i])) {
          j++;
        } else {
          result.push_back({nums[i], nums[j], nums[k]});
          // Gotta check for duplicate here
          while (j < k && nums[j] == nums[j + 1])
            j++;
          j++;
        }
      }
    }
    return result;
  }
};
