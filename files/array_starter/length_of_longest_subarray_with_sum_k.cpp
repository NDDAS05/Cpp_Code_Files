/*
Problem Statement: Given an array containing both positive and negative
integers, we have to find the length of the longest subarray with the sum of all
elements equal to zero.

Example 1:
Input:
 N = 6, array[] = {9, -3, 3, -1, 6, -5}
Result:
 5
Explanation:
 The following subarrays sum to zero:
- {-3, 3}
- {-1, 6, -5}
- {-3, 3, -1, 6, -5}
The length of the longest subarray with sum zero is 5.

Example 2:
Input:
 N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10}
Result:
 8
Explanation:
 Subarrays with sum zero:
- {-2, 2}
- {-8, 1, 7}
- {-2, 2, -8, 1, 7}
- {6, -2, 2, -8, 1, 7, 4, -10}
The length of the longest subarray with sum zero is 8.
*/

// Hash map approach
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  int largestSubarraySumK(vector<int> &nums, int k) {
    int i = 0;
    long long int preSum = 0;
    unordered_map<long long int, int> mp;
    mp[0] = -1;
    int largest_len = 0;

    for (; i < nums.size(); i++) {
      preSum += nums[i];
      if (mp.find(preSum) == mp.end()) // Presum not found
        mp[preSum] = i;
      if (mp.find(preSum - k) != mp.end())
        largest_len = std::max(largest_len, i - mp[preSum - k]);
    }
    return largest_len;
  }
};
