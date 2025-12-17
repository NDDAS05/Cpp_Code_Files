#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> maxSubarraySumArray(std::vector<int> &nums) {
    // For handling negative, +ve, both elements: Kadane Logic changes slightly.
    // Instead of resetting sum to 0, at each step which is feasible:
    // currentSum=currentSum+arr[i] or currentSum=arr[i] depending on which one
    // is more profitable i.e. gives max value. currentSum=arr[i] means new
    // sub-array starts. That means update currentStart to that i. If max
    // changes, change startArr to currentStart and also endArr to i.

    int size = (int)nums.size(), currentStart = 0, maxSum = nums[0], i = 0,
        startArr = 0, endArr = 0, currentSum = nums[0];
    for (i = 1; i < size;
         i++) { // Note array starts from 2nd element here. Since we need to
                // compare nums[i-->Can not be done if started from 0] and
                // currentSum+nums[i]
      if (currentSum + nums[i] > nums[i]) {
        currentSum +=
            nums[i]; // We keep adding new ele so no need to modify startArr
      } else {
        currentSum = nums[i];
        currentStart = i;
      }

      if (maxSum < currentSum) {
        maxSum = currentSum;
        // max updated so change endArr
        endArr = i;
        // change startArr too
        startArr = currentStart;
      }
    }
    std::vector<int> vec = {startArr, endArr, maxSum};
    return vec;
  }
};

int main() {
  std::vector<int> nums = {-11, -21, -9, -11};
  Solution s;
  std::vector<int> vec = s.maxSubarraySumArray(nums);
  for (int i : vec)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
