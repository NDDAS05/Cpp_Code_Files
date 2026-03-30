/*
 229. Majority Element II

Given an integer array of size n, find all elements that appear more
than ⌊ n/3 ⌋ times.



Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]


Constraints:

1 <= nums.length <= 5 * 10^4
-10^9 <= nums[i] <= 10^9


Follow up: Could you solve the problem in linear time and in O(1) space?
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> majorityElement(vector<int> &nums) {
    // Voting for more than one here.
    int ele1 = INT_MIN, count1 = 0;

    int ele2 = INT_MIN, count2 = 0;

    // Voting logic:
    vector<int> vec;

    for (int i = 0; i < nums.size(); i++) {
      // If count 0, set element.
      // If matching element increment count.
      // If not matching (with either), decrement votes of BOTH
      // Ensure ele1 and ele2 are not same while count =0
      // CUZ:     2     1     1         3         1
      // Vote:  e1(1) e2(1) e2(2) [e1(0) e2(1)] e1(1)
      // So at the end e1 and e2 both 1 which is not correct.

      // Initialization class
      if (count1 == 0 && nums[i] != ele2) {
        // if ele2 is not already holding what we are
        // about to hold
        ele1 = nums[i];
        count1++;
      }

      else if (count2 == 0 && nums[i] != ele1) {
        // Similar logic.
        ele2 = nums[i];
        count2++;
      }

      // Increment case:
      else if (nums[i] == ele1)
        count1++;
      else if (nums[i] == ele2)
        count2++;

      else {
        count1--;
        count2--;
      }
    }
    // Repurposing those count vars
    count1 = 0;
    count2 = 0;

    // Checking if they do appear n/3 times.
    for (int i : nums)
      if (i == ele1)
        count1++;
    for (int i : nums)
      if (i == ele2)
        count2++;

    if (count1 > nums.size() / 3)
      vec.push_back(ele1);
    if (count2 > nums.size() / 3)
      vec.push_back(ele2);

    return vec;
  }
};
