#include <bits/stdc++.h>
#define endl std::endl

class solution {
public:
  int maxConsecutiveOnes(std::vector<int> &nums, int k) {
    int l = 0, r = 0, maxlen = 0, count = 0,
        allowedZero = k, // Further number of zeroes that can be added
        currentZero = 0, // Currently number of zeroes in the window
        size = nums.size();

    while (r < size) // Scanning current element, not the next one.
    {
      if (nums[r] == 0) { // That means current element is zero.
        allowedZero--;
        currentZero++;

        while (allowedZero <
               0) { // In this condition, r is pointing the next zero after
                    // limit-> due to current processing, allowedZero-- will be
                    // executed first so allowedZero will become (-1); so
                    // increase l such that allowedZero becomes 0 again.
          if (nums[l] == 0) {
            allowedZero++;
            currentZero--;
          }
          l++;
        }
      }
      count = r - l + 1;
      maxlen = std::max(count, maxlen);
      r++;
    }
    return maxlen;
  }
};

int main() {
  int k = 2, res;
  std::vector<int> vec = {0};
  solution s;
  res = s.maxConsecutiveOnes(vec, k);
  std::cout << res << endl;
  return 0;
}
