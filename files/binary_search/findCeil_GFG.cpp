#include <iostream>
#include <vector>
using namespace std;

/*
Ceil in a Sorted Array
Link: https://www.geeksforgeeks.org/problems/ceil-in-a-sorted-array/1

Given a sorted array arr[] and an integer x,
find the index (0-based) of the smallest element in arr[]
that is greater than or equal to x.
This element is called the ceil of x.

If such an element does not exist, return -1.

Note: In case of multiple occurrences of ceil of x, return the index of the
first occurrence.

Examples

Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 5
Output: 2
Explanation: Smallest number greater than 5 is 8, whose index is 2.

Input: arr[] = [1, 2, 8, 10, 11, 12, 19], x = 20
Output: -1
Explanation: No element greater than 20 is found. So output is -1.

Input: arr[] = [1, 1, 2, 8, 10, 11, 12, 19], x = 0
Output: 0
Explanation: Smallest number greater than 0 is 1, whose indices are 0 and 1. The
index of the first occurrence is 0.

Constraints:
1 ≤ arr.size() ≤ 10^6
1 ≤ arr[i] ≤ 10^6
0 ≤ x ≤ arr[n-1]
*/

class solution {
public:
  int findCeil(vector<int> &arr, int target) {
    // Now we are moving <----- direction.
    // If low targ mid high
    int low = 0, high = arr.size() - 1;
    int mid, result = -1;

    while (low <= high) {
      mid = low + (high - low) / 2;
      if (arr[mid] >= target) { // [low] [target] [mid | target] [high]
        result = mid;
        high = mid - 1;
      }

      else
        low = mid + 1;
    }

    return result;
  }
};
