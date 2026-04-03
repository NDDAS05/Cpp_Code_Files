/*
18. 4Sum
Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
* 0 <= a, b, c, d < n

* a, b, c, and d are distinct.
* nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.



Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

1 <= nums.length <= 200
-10^9 <= nums[i] <= 10^9
-10^9 <= target <= 10^9
*/

/*
 * PITFALLS TO AVOID (4Sum / k-Sum Problems):

 * * 1. INNER LOOP LOGIC:

 * The two-pointer technique (k and l) requires a nested 'while' loop.
 * Without it, the code only checks one pair of pointers for every
 * iteration of the outer loop, missing the majority of potential
 * combinations.

 * * 2. GOAL VS. TARGET COMPARISON:

 * When reducing the problem from 4Sum to 2Sum, ensure the final
 * two-pointer sum is compared against the 'remaining goal'
 * (target - first_num - second_num) rather than the original
 * global target.

 * * 3. UNSIGNED SIZE UNDERFLOW (size_t):

 * 'vector.size()' returns an unsigned integer. Subtracting from it
 * (e.g., size - 3) when the size is small can cause an underflow,
 * wrapping to a massive positive number and causing out-of-bounds
 * access or infinite loops. Always check size constraints or
 * cast to a signed int.

 * * 4. 32-BIT INTEGER OVERFLOW:

 * Standard 'int' caps at ~2.14 billion. Summing multiple large
 * values (e.g., 10^9 + 10^9) or subtracting from a negative target
 * can exceed this limit. Use 'long long' for intermediate
 * calculations to prevent runtime errors.

 * * 5. DUPLICATE HANDLING:

 * Ensure 'while' loops are used to skip identical values for all
 * four pointers to avoid returning redundant quadruplets in the
 * result set.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;

    if (nums.size() < 4)
      return result; // Cuz, nums.size starts from 1 in this question.

    long long int i, j, k, l; // Int can hold UPTO 2*10^9.
    // But for 3 ints, it may get < or > that range. (Our case sum[2 nums] and
    // target)

    for (i = 0; i < nums.size() - 3; i++) {
      // Dup check
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      j = i + 1;

      for (; j < nums.size() - 2; j++) {
        k = j + 1;
        l = nums.size() - 1;
        long long int sum = nums[i] + nums[j];
        long long int goal = target - sum;

        while (k < l && k < nums.size() && l < nums.size()) {
          sum = nums[k] + nums[l];
          if (sum > goal) {
            l--;
          } else if (sum < goal) {
            k++;
          } else {
            result.push_back({nums[i], nums[j], nums[k], nums[l]});
            // increment j while noting for dupes.
            while (k < l && nums[k] == nums[k + 1])
              k++;
            k++;
            l--; // If j increases, definitely k will decrease to
                 // make sum similar.
          }
        }

        while (j < nums.size() - 2 && nums[j] == nums[j + 1])
          j++;
        // j++ will mandatorily happen in next i loop iteration.
        // So j will, after 1st time, always point to next unique element.
      }
    }
    return result;
  }
};
