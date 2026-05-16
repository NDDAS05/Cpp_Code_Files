#include <bits/stdc++.h>
#define endl std::endl

class solution {
public:
  void moveZeroes(std::vector<int> &nums) {
    int i = 0, j = 0, size = nums.size();

    while (j < size) {
      if (nums[j] != 0) {
        nums[i] =
            nums[j]; // Copying non zero elements to the beginning of the array
        i++; // I starts from first and pushes non zero ele to front (non zero ,
             // not distinct)
      }
      j++; // J iterates, and tracks non zero vals
    }
    while (i < size) { // After j reached size, that means we got all non zero,
                       // so make rest =0
      nums[i] = 0;
      i++;
    }
  }
};

int main() {
  std::vector<int> num = {0, 1, 2, 0, 0, 0, 4, 5, 0, 0, 0, 0, 0, 6,
                          0, 7, 8, 0, 0, 0, 9, 0, 0, 0, 0, 0, 10};
  for (int i : num)
    std::cout << i << " ";
  std::cout << endl;
  solution s;
  s.moveZeroes(num);
  for (int i : num)
    std::cout << i << " ";
  std::cout << endl;
  return 0;
}
