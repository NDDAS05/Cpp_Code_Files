#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
#define endl std::endl

class Solution {
public:
  int maxProfit(std::vector<int> &nums) {
    size_t i = 0;
    int maxProfit = INT_MIN, minBuyPrice = INT_MAX;
    size_t size = nums.size();

    for (i = 0; i < size; i++) {
      minBuyPrice = std::min(nums[i], minBuyPrice);
      maxProfit = std::max(maxProfit, nums[i] - minBuyPrice);
    }
    return maxProfit;
  }
};

int main() {
  std::vector<int> vec = {7, 2, 5, 3, 6, 4};
  std::vector<int> vec2 = {3, 1, 4, 9, 6, 2, 1, 7, 8, 4, 2, 1, 9};
  Solution s;
  std::cout << s.maxProfit(vec) << endl;
  std::cout << s.maxProfit(vec2) << endl;
  return 0;
}
