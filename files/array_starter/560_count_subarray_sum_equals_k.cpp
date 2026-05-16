/*
560. Subarray Sum Equals K
Given an array of integers nums and an integer k, return the total number of
subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.



Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


Constraints:

1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
*/

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int count = 0, preSum = 0;

    // Map structure: [preSum upto now, frequency of occurence of this preSum
    // upto now]
    unordered_map<int, int> umap;
    umap[0] = 1;

    for (int i : nums) {
      // Update prefix sum.
      preSum += i;

      // If preSum - k exists update counter.
      if (umap.find(preSum - k) != umap.end())
        count += umap[preSum - k];
      umap[preSum]++;
    }
    return count;
  }
};
