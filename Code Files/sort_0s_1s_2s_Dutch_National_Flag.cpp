#include <bits/stdc++.h>
#define endl std::endl

class Solution {
public:
  void sortColors(std::vector<int> &nums) {
    // Dutch National Flag (DNF) Algorithm
    // If array contains 3 distinct elements- Have 2 pointers leftBorder and
    // rightBorder, and one middile. leftBorder: Defines lowest/highest (depends
    // on order) rightBorder: Defines highest/lowest (depends on order)
    //
    // mid starts from leftBorder to <=rightBorder
    // ***Equality is important because otherwisi it will skip 1 element.
    // Explanation after logic
    //(Assuming 0 1 2 and ascending order)
    // If mid ==0, swap with leftBorder and increment leftBorder and mid
    // If mid ==1 ignore move mid +1
    // If mid ==2 Swap with rightBorder and rightBorder-- BUT do not move mid:
    // Check mid again in next iteration Since array starts with mid=low
    // position, it is necessary to move mid whenever moving leftBorder but not
    // so for right border.
    // Now if it was (mid<rightBorder) in while clause:
    // Say array [2,0,1]. After 1st pass: [1(leftBorder, mid), 0(rightBorder),
    // 2] Now mid++ since 1 so [1(leftBorder),    0(rightBorder, mid), 2] Now
    // loop breaks, it never checks current rightBorder. Since, rightBorder
    // points the element BEFORE 2 not 2 We are essentially skipping its
    // placement.

    int leftBorder = 0, size = (int)nums.size();
    int rightBorder = size - 1;
    int mid = 0;

    while (mid <= rightBorder) {
      if (nums[mid] == 1)
        mid++;
      else if (nums[mid] == 0) { // Swap with leftBorder
        std::swap(nums[mid], nums[leftBorder]);
        mid++;
        leftBorder++;
      } else {
        std::swap(nums[mid], nums[rightBorder]);
        rightBorder--;
        // No mid updating, we still need to check if it is 0 1 or 2
      }
      for (int i : nums)
        std::cout << i << " ";
      std::cout << endl;
    }
  }
};

int main() {
  std::vector<int> vec = {2, 0, 1};
  Solution s;
  s.sortColors(vec);
  for (int i : vec)
    std::cout << i << " ";
  std::cout << endl;
  return 0;
}
