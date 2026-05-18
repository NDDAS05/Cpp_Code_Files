#include <iostream>
#include <vector>
using namespace std;

// Special case here: There is LITERALLY no way to say which side is sorted if
// low==mid==high. 1 1 1 1 1 0 1 1  |  Another: 1 1 1 0 1 1 1 1 1 1 There IS no
// information about this. In that case, binary search solution CAN degrade to
// O(n) This is the key takeaway.
//
/* At many positions:

low == mid == high

We literally cannot infer:

where pivot is
which side is sorted
which half is safe to discard

No clever variables can recover information that the input itself hides.*/
// So we instead manually reduce search space by 2 (low++, high--) to see if
// anything can be done.
class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int low = 0, high = nums.size() - 1, mid;

    while (low <= high) {
      mid = low + (high - low) / 2;
      if (target == nums[mid])
        return true;
      else if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
        low++;
        high--;
      }

      else if (nums[mid] <= nums[high]) {
        if (target >= nums[mid] && target <= nums[high])
          low = mid + 1;
        else
          high = mid - 1;
      } else {
        if (target >= nums[low] && target <= nums[mid])
          high = mid - 1; // 22 4 |4| 4 11
        else
          low = mid + 1;
      }
    }

    return false;
  }
};

int main() {
  vector<int> vec = {1, 1, 1, 0, 1, 1};
  int target;
  cin >> target;
  solution s;
  cout << s.search(vec, target) << endl;
  return 0;
}
