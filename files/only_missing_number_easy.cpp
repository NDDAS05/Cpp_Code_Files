#include <bits/stdc++.h>
#define endl std::endl

class Solution {
public:
  int missingNumber(std::vector<int> &nums) {
    int n = nums.size();
    n = n * (n + 1) * 0.5;
    int prefixSum = 0;
    for (int i : nums) {
      prefixSum += i;
    }

    return (n - prefixSum);
  }
};

int main() {
  int res;
  std::vector<int> vec = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  Solution s;
  res = s.missingNumber(vec);
  std::cout << res << endl;
  return 0;
}
