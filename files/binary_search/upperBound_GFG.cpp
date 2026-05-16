#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int upperBound(vector<int> &arr, int target) {
    // code here
    int low = 0, high = arr.size() - 1, mid;
    int result = arr.size();

    while (low <= high) {
      mid = low + (high - low) / 2;

      if (arr[mid] <= target) // Upper bound can not be here.
        low = mid + 1;
      else
        result = mid;
      high = mid - 1;
    }

    return result;
  }
};

int main() {
  Solution s;
  vector<int> vec = {2, 3, 7, 10, 11, 11, 25};
  cout << s.upperBound(vec, 11) << endl;

  return 0;
}
