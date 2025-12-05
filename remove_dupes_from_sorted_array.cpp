#include <bits/stdc++.h>
#include <vector>

class solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    std::vector<int> unique;
    int elem;

    // Forward pass to check for unique elements
    elem = INT_MIN;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] != elem) {
        unique.push_back(nums[i]);
        elem = nums[i];
      }
    }
    size = unique.size();
    // Array should have unique elements after pushing
    for (int i = 0; i < size; i++) {
      nums[i] = unique[i];
    }
    return size;
  }
};
