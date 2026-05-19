#include <iostream>
#include <vector>
using namespace std;
/*
540. Single Element in a Sorted Array

You are given a sorted array consisting of only integers where every element
appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.



Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10


Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5
*/

class Solution {
public:
  int singleNonDuplicate(vector<int> &nums) {
    // Possible array structures considered:
    // [1] 2 2 3 3 4 4 5 5 <single at first>
    // 1 1 2 2 3 3 4 4 [5] <single at last>
    // 1 1 [2] 3 3 4 4 5 5 <non-symmetric: single before mid>
    // 1 1 2 2 3 3 [4] 5 5 <non-symmetric: single AFTER mid>
    // 1 1 2 2 [3] 4 4 5 5 <symmetric: single AT the mid>
    // INDICES
    // 0 1 2 3 4 5 6 7 8
    //
    // Notice: Before mid,
    //  1  1  2  2  3  3
    // [0][1][2][3][4][5]
    // Before single all unique begins AT even indices.
    //  |1| 2  2  3  3  4  4
    //  [0][1][2][3][4][5][6]
    // After single, all unique ENDS INSTEAD at even index.
    // given all before mid ends at odd, mid is ALWAYS AT AN EVEN IDX.
    // That means solution can NOT EXCLUDE even indices. But can exclude odd
    // ones.
    //
    // =====================
    // |   Approach
    // =====================
    //
    // We calculate mid and always shift mid back to even idx if its odd.
    // Given that: before single: unique begins at even,
    // so the following idx value will also be same as the even idx value.
    //
    // This is the part we can safely ignore as it is confirmed to be BEFORE
    // SINGLE. We skip ahead of those pair of same ele by low=mid+2;
    //
    // Now if mid!=mid+1 that means: unique ends at even idx OR/AND mid is the
    // single one . SINGLE can not lie AFTER mid here: it will be AT mid . If it
    // was true then that would be mid=mid+1 case. In that case we can safely
    // ignore the right part, BUT we still do NOT know if mid is after single or
    // is the single So we do : high = mid; instead of typical high = mid - 1.
    //
    // Finally since we are eliminating before and after portion of mid, soln
    // will END WHEN BOTH SIDES ARE GONE AND ONLY SINGLE ONE IS LEFT. thus
    // returning condition: if(low==high).
    int low = 0, high = nums.size() - 1, mid;

    while (low <= high) {
      mid = low + (high - low) / 2;
      if ((mid & 1) == 1)
        mid--;

      if (low == high)
        return nums[low];
      else if (nums[mid] == nums[mid + 1])
        low = mid + 2;
      else
        high = mid;
      // mid!=mid+1
      // This implies mid is AFTER single element
      // Or, mid IS the single element
    }
    return -1;
  }
};
