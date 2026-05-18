#include <iostream>
#include <vector>
using namespace std;

class solution {
public:
  // Logic: I have used "Binary Elimination" here eliminating case by case.
  // Array Styles considered:
  //    |---------X-------| o |---------------|
  //   low       mid                         high
  //
  //   |-----------------| o |----X----------|
  //  low                        mid        high
  //
  //  o |----------------X------------------|
  // low                mid                high
  int search(vector<int> &nums, int target) {
    int low, high, mid;
    low = 0;
    high = nums.size() - 1;

    while (low <= high) {
      mid = low + (high - low) / 2;
      if (target == nums[mid])
        return mid;                  // BASE CASE
      else if (target > nums[mid]) { // x: start of rotated sorted array
        // This means: [low]--- [mid] ---<targ>---- x -----[high]
        // Or:         [low]-- <targ>---- x ---[mid]-------[high]
        // Or:         [low]------ x -----[mid]---<targ>---[high]
        // Or:         [low] x----------[mid]-----<targ>---[high]
        //
        // Now for case 2: high = mid-1, for 1, 3 AND 4 low = mid +1.
        // I attempted to find them using high and mid.
        // We already know target > mid. If its lesser than high, then only
        // possible case 3 and 4

        if (target <= nums[high])
          low = mid + 1;
        // But if target > high, we have case 1 and 2.
        // If mid > low (target > mid and target > high), case 1 (low adjust).
        // else case 2.
        else {
          if (nums[mid] > nums[high])
            low = mid + 1;
          else
            high = mid - 1;
        }
      }

      else if (target < nums[mid]) {
        // This means: [low]---<targ>---[mid]--- X-----[high]
        // Or:         [low]---[mid]--- X ---<targ>-----[high]
        // Or:         [low]------- X --<targ>---[mid]--[high]
        // Or:         [low] X ----<targ>----[mid]------[high]
        //
        // If target > high (and <mid) then ONLY case 1 possible. So high goes
        // down.
        if (target > nums[high])
          high = mid - 1;
        // If target < high (and < mid), 2,3,4 all possible.
        // If mid < high, they are in rotated part. Targ <mid <high means it is
        // also between X and mid. So high goes down.
        //
        // If mid > high and target < mid AND <high, that means , mid comes
        // AFTER high. target is in rotated area after x, mid is in non rotated
        // area BEFORE X. so [low]   [mid]   X   <target>   [high] : Clearly
        // gotta adjust low.
        else {
          if (nums[mid] < nums[high])
            high = mid - 1;
          else
            low = mid + 1;
        }
      }
    }

    return -1;
  }

  int search_optimized(vector<int> &nums, int target) {
    // Set the search space to entire array
    int low = 0;
    int high = nums.size() - 1;

    // Continue until the search space becomes invalid
    while (low <= high) {

      // Find the middle index
      int mid = (low + high) / 2;

      // If the target is found at mid, return mid
      if (nums[mid] == target)
        return mid;

      // Check if the left half is sorted
      if (nums[low] <= nums[mid]) {

        // If target lies in the sorted left half, search there
        if (nums[low] <= target && target < nums[mid]) {
          high = mid - 1;
        }
        // Else search in the right half
        else {
          low = mid + 1;
        }
      }

      // Otherwise, right half is sorted
      else {

        // If target lies in the sorted right half, search there
        if (nums[mid] < target && target <= nums[high]) {
          low = mid + 1;
        }
        // Else search in the left half
        else {
          high = mid - 1;
        }
      }
    }

    // If not found, return -1
    return -1;
  }
};

int main() {
  vector<int> vec = {4, 0, 1, 2, 3};
  solution s;
  cout << s.search(vec, 4) << endl;
  return 0;
}
