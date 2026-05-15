/*
 *
152. Maximum Product Subarray
Medium

Given an integer array nums, find a subarray that has the largest product, and
return the product. The test cases are generated so that the answer will fit in
a 32-bit integer. Note that the product of an array with a single element is the
value of that element.

Example 1:

Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:

Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


Constraints:

1 <= nums.length <= 2 * 10^4
-10 <= nums[i] <= 10
The product of any subarray of nums is guaranteed to fit in a 32-bit integer.
*/

#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int> &nums) {
    // We need both max and min product here.
    // WHY?
    // Min here is min upto current index. We track this because: a
    // A min multipied by a -ve number may become max.
    // Again a max atp multiplied by a -ve may become minimum number.
    //
    // These 2 are also not enough. They are instantaneous.
    // We also need another variable to track overall max we have seen through
    // this process.
    //
    int result = nums[0];
    int max_so_far = nums[0];
    int min_so_far = nums[0];

    for (int i = 1; i < nums.size(); i++) {

      // Swapping logic:
      if (nums[i] < 0)
        swap(max_so_far, min_so_far);

      // Calculation
      max_so_far = max(
          nums[i],
          max_so_far *
              nums[i]); // This can be either cumulative or restarted from here.

      min_so_far = min(min_so_far * nums[i], nums[i]); // Same for this.

      // This allows us to skip 0s.
      //  At 0, max AND min will become 0 [Remember ultimate max is being
      //  tracked by result] At next index, max will be current OR 0 (0*current)
      //  Same for min.
      //
      //  So we are successfully tracking after 0.
      result = max(max_so_far, result);
    }
    return result;
  }
};

int main() {
  vector<int> vec = {2, -3, 1, 2, -4, 3, -2};
  Solution s;
  cout << s.maxProduct(vec) << endl;
  return 0;
}
