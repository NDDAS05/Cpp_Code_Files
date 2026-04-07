#include <bits/stdc++.h>
#define endl std::endl

class solution {
public:
  int findMaxConsecutiveOnes(std::vector<int> &nums) {
    int maxcount = 0, count = 0, size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] == 1) {
        count++;
        maxcount = std::max(maxcount, count);
      }

      else {
        count = 0;
      }
    }

    return maxcount;
  }
};

int main() {
  std::vector<int> vec = {1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1};
  solution s;
  int res = s.findMaxConsecutiveOnes(vec);
  std::cout << res << endl;
  return 0;
}
