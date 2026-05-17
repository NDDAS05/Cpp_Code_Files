#include <iostream>
#include <vector>
using namespace std;
/*
Floor in a Sorted Array

Link:
https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1

Given a sorted array arr[] and an integer x,
find the index (0-based) of the largest element in arr[] that is less than or
equal to x. This element is called the floor of x.

If such an element does not exist, return -1.

Note: In case of multiple occurrences of floor of x, return the index of the
last occurrence.

Examples

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 5
Output: 1
Explanation: Largest number less than or equal to 5 is 2, whose index is 1.

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 11
Output: 4
Explanation: Largest Number less than or equal to 11 is 10,
whose indices are 3 and 4.
The index of last occurrence is 4.

Input: arr[] = [1, 2, 8, 10, 10, 12, 19], x = 0
Output: -1
Explanation: No element less than or equal to 0 is found. So, output is -1.
*/

class Solution {
public:
  int findFloor(vector<int> &arr, int x) {
    // Largest ele less than equal to x.
    // IDX of last occurence.
    // Thinking first in terms of: 1st ele greater than target -1.
    int low = 0, high = arr.size() - 1;
    int result = 0, mid;
    if (arr[high] <= x)
      return high;
    // Finding out first ele greater than x (target)
    while (low <= high) {
      mid = low + (high - low) / 2;
      if (x >= arr[mid]) {
        low = mid + 1;
      } else { // mid>target
        result = mid;
        high = mid - 1;
      }
    }
    return result - 1;
  }

  int findFloor_optimized(vector<int> &arr, int target) {
    // First think: we need largest ele smaller/equal to target.
    // So we will be constantly moving ---> direction.
    // So, if target >= mid, update result to mid, then do low=mid+1;
    // This makes it so even for dupes, we are moving to the end of the dupes.
    int low = 0, high = arr.size() - 1;
    int result = -1, mid;
    while (low <= high) {
      mid = low + (high - low) / 2;

      if (target >= arr[mid]) { //[low] [mid]...<target>...[high]
        // If mid = target, move towards end
        // If mid != target, move right towards target
        // And save current val as the potential only element largest-lesser
        // than target.

        result = mid;
        low = mid + 1;
      } else
        high = mid - 1; // [low] <target> [mid] [high]
      // attempting to go to [low] <target[mid]> [high] |old_mid|
    }
    return result;
  }
};

int main() {
  vector<int> vec = {1, 2, 8, 10, 10, 12, 19};
  Solution s;
  cout << s.findFloor_optimized(vec, 99) << endl;
  return 0;
}
