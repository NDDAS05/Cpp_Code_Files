#include <iostream>
#include <vector>
using namespace std;

/*
34. Find First and Last Position of Element in Sorted Array
Link:
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

Given an array of integers nums sorted in non-decreasing order, find the
starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.



Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

-  0 <= nums.length <= 10^5
- -10^9 <= nums[i] <= 10^9
-  nums is a non-decreasing array.
- -10^9 <= target <= 10^9

*/

class solution {
public:
  int binarySearch(vector<int> &nums, int target, bool firstOccurence) {
    int low = 0, high = nums.size() - 1;
    int mid, result = -1;

    while (low <= high) {
      mid = low + (high - low) / 2;

      if (target == nums[mid]) {
        if (firstOccurence) {
          result = mid;
          high = mid - 1;
        } // For 1st occurence we move <----

        else {
          result = mid;
          low = mid + 1;
        } // For last occurence we move ---->
      }

      else if (target < nums[mid])
        high = mid - 1;
      else
        low = mid + 1;
    }
    return result;
  }
  vector<int> searchRange(vector<int> &nums, int target) {
    return {
        binarySearch(nums, target, true),
        binarySearch(nums, target, false)}; // vector can be returned as pair.
  }
};

int main() {
  vector<int> vec = {5, 7, 7, 8, 8, 10};
  solution s;
  vector<int> result = s.searchRange(vec, 8);
  for (int i : result)
    cout << i << endl;
  return 0;
}
