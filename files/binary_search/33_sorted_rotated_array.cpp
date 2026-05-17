#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
  int search(vector<int> &nums, int target) {
    // First searching for the sorted space.
    int low = 0, high = nums.size() - 1, mid;
    int rotated_start = 0;
    while (low <= high) {
      mid = low + (high - low) / 2;
      // 4 5 6 0 1 2
      // If low, high bigger than mid, mid is in "rotated" part.
      // Move <----
      if (nums[low] > nums[mid] && nums[high] > nums[mid]) {
        rotated_start = mid;
        high = mid - 1;
      } else if (nums[low] < nums[mid] && nums[high] < nums[mid])
        low = mid + 1;
      else {
        rotated_start = low;
        high = mid - 1;
      }
    }

    return rotated_start;
  }
};

int main() {
  vector<int> vec = {4, 0, 1, 2, 3};
  solution s;
  cout << s.search(vec, 4) << endl;
  return 0;
}
