#include <algorithm>
#include <iostream>
#include <vector>
#define endl std::endl

class Solution {
public:
  std::vector<int> replaceElements(std::vector<int> &nums) {
    int size = (int)nums.size(), i = size - 2, rightmax = nums[size - 1],
        currentElem;
    if (size == 1) {
      nums[0] = -1;
      return nums;
    }
    while (i >= 0) {
      currentElem = nums[i];
      nums[i] = rightmax;
      rightmax = std::max(rightmax, currentElem);
      i--;
    }
    nums[size - 1] = -1;
    return nums;
  }
};

int main() {
  std::vector<int> vec = {5, 4, 3, 2, 1};
  for (int i : vec)
    std::cout << i << " ";
  std::cout << endl;

  Solution s;
  vec = s.replaceElements(vec);
  for (int i : vec)
    std::cout << i << " ";
  std::cout << endl;
  return 0;
}
