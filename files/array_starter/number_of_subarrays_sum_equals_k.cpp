#include <iostream>
#include <vector>
#define endl std::endl

class Solution {
public:
  int subarraySum(std::vector<int> &nums, int k) {
    int i = 0, j = 0, subarr_count = 0, window_sum = nums[0],
        size = (int)nums.size();
    while (j < size) {
      while (window_sum >= k && i < j) {
        window_sum -= nums[i];
        if (window_sum == k)
          subarr_count++;
        i++;
      }
      if (window_sum == k)
        subarr_count++;
      j++;
      window_sum += nums[j];
    }
    return subarr_count;
  }
};

int main() {
  std::vector<int> vec = {0, 4, 0};
  int result;
  Solution s;
  result = s.subarraySum(vec, 4);
  std::cout << result << endl;
  return 0;
}
