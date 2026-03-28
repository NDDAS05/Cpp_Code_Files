// A continuous sub-array is nice if it has k odd element in it.
// We have to count number of all possible such nice sub-arrays.

#include <bits/stdc++.h>
#define endl std::endl

class Solution {
public:
  int countArr(std::vector<int> &nums, int k) {
    if (k < 0)
      return 0;
    int left = 0, right = 0, size = (int)nums.size(), oddCount = 0,
        arrayCount = 0;
    while (right < size) {
      oddCount += (nums[right] % 2); // Odd hole 1 add hobe na hole hobe na.

      while (oddCount > k) {
        oddCount -= (nums[left] % 2);
        left++;
      }
      arrayCount = arrayCount + (right - left + 1);
      right++;
    }
    return arrayCount;
  }
  int numberOfSubarrays(std::vector<int> &nums, int k) {
    return (countArr(nums, k) - countArr(nums, k - 1));
  }
};

int main() {
  int res;
  std::vector<int> vec = {2, 4, 6};
  Solution s;
  res = s.numberOfSubarrays(vec, 2);
  std::cout << res << endl;
  return 0;
}
