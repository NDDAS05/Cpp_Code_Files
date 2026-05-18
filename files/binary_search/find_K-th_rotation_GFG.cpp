#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findKRotation(vector<int> &arr) {
    int low = 0, mid, high = arr.size() - 1;
    int minimum_idx = high;

    while (low <= high) {
      mid = low + (high - low) / 2;
      if (arr[low] <= arr[mid]) {
        // Just storing the minimum index instead of absolute minimum value.
        if (arr[low] < arr[minimum_idx])
          minimum_idx = low;
        low = mid + 1;
      } else {
        if (arr[mid] < arr[minimum_idx])
          minimum_idx = mid;
        high = mid - 1;
      }
    }
    return minimum_idx;
  }
};
