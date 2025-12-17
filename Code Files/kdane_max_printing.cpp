#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
  std::vector<int> maxSubarraySumArray(std::vector<int> &nums) {
    int size = nums.size(), currentSum = 0, maxSum = INT_MIN, i = 0, endArr,
        startArr, currentStart = 0;
    for (i = 0; i < size; i++) {
      currentSum += nums[i];
      if (currentSum < 0) {
        currentSum = 0;
        currentStart = i + 1;
      }

      if (maxSum < currentSum) {
        // Update max sum to currentSum
        maxSum = currentSum;
        endArr = i;
        startArr = currentStart;
      }
    }
    std::vector<int> vec = {startArr, endArr, maxSum};
    return vec;
  }
};

int main() {
  std::vector<int> nums = {1, 1, 0, 2, 3, 4, -4, -6, 10};
  Solution s;
  std::vector<int> vec = s.maxSubarraySumArray(nums);
  for (int i : vec)
    std::cout << i << " ";
  std::cout << std::endl;
  return 0;
}
