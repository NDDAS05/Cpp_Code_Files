#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
  int lowerBound(vector<int> &arr, int target) {
    int low = 0, high = arr.size() - 1, mid;

    while (low <= high) {
      mid = low + (high - low) / 2;

      if (target == arr[mid])
        break; // Matched
      else if (target > arr[mid])
        low = mid + 1;
      else
        high = mid - 1;
    }
    // Matched OR not matched

    if (arr[mid] == target) {
      while (mid - 1 >= 0 && arr[mid - 1] == target)
        mid--;
      return mid;
    }

    if (low < 0 || high > arr.size() - 1)
      return arr.size();
    if (arr[mid] >= target)
      return mid;
    else
      return mid + 1;
  }

  int lowerBound_optimized(vector<int> &arr, int target) {
    // Here we optimize duplicate and correct index handling cases.
    // If array is like     a    b    d     d     d   d   d   d   <target = c>
    //                    [low]           [mid]             [high]
    // Finally, we will get a condition where [low][mid][high] pointing io
    // same location. Followed by that, low goes ahead of high, mid and high
    // points to correct starting, but low is NOT. If shit is not found in the
    // array we are BY DEFAULT returning array.size().
    //
    int low = 0, high = arr.size() - 1, mid;
    int result = arr.size(); // Default return value.

    while (low <= high) {
      mid = low + (high - low) / 2;

      if (target <= arr[mid]) {
        result = mid; // Posible return value. Refined in further iterations.
        high = mid - 1;
      } else
        low = mid + 1;
    }
    return result;
  }
};
