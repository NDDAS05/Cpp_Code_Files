#include <bits/stdc++.h>
#include <vector>
#define endl std::endl

class Solution {
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
    // If we sort it from the front,
    // Data of nums1 will get deleted.
    // Since nums1 has all 0s at the back,
    // We sort from LAST.
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] >= nums2[j]) {
        nums1[k] = nums1[i];
        k--;
        i--;
      } else {
        nums1[k] = nums2[j];
        j--;
        k--;
      }
    }
    // Push remaining
    // Since we are putting into nums1, if nums1 elements are remaining, they
    // are already in the correct order
    while (j >= 0) {
      nums1[k] = nums2[j];
      k--;
      j--;
    }
  }
};

int main() {
  std::vector<int> vec = {1, 5, 6, 0, 0, 0, 0};
  std::vector<int> vec2 = {2, 4, 6, 9};
  Solution s;
  s.merge(vec, 3, vec2, 4);
  for (auto i : vec) {
    std::cout << i << " ";
  }
  std::cout << endl;
  return 0;
}
