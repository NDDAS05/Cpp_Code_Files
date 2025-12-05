#include <bits/stdc++.h>
#define endl std::endl
class solution {
public:
  int removeDuplicates(std::vector<int> &nums) {
    size_t i = 0, j = 0, size;
    size = nums.size();
    int count = 1; // At least 1 unique element would be there
    for (j = 0; j < size; j++) {
      // Logic: J advances. If anywhere new element is found, j copies that to
      // i+1 and i moves fwd by 1;
      if (nums[i] != nums[j]) {
        i = i + 1;
        count++;
        nums[i] = nums[j];
      }
    }
    return count;
  }
};

int main() {
  int soln;
  solution obj1;
  std::vector<int> vec = {1, 1, 2, 2, 3, 3, 20, 35, 35, 50, 50, 100, 100, 101};
  soln = obj1.removeDuplicates(vec);
  std::cout << soln << endl;
  for (int i : vec) {
    std::cout << i << endl;
  }
  return 0;
}
