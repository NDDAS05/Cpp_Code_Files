#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
  int possibleBoq(vector<int> &bloomDay, int day,
                  int max_flower) { // max_flower : k
    // day : basically mid
    // This function returns max number of bouquets possible on given day

    int i = 0, j = 0, boq_no = 0;
    while (i < bloomDay.size()) {
      if (bloomDay[i] <= day) {
        bool pos = true; // If boq possible.
        j = i;
        while ((j - i) < max_flower) { // Runs untill valid number of adjacent
                                       // flowers are picked.
          if ((j < bloomDay.size()) && (bloomDay[j] <= day))
            j++; // Included in boq
          else { // Valid no of flowers could not be taken.
            pos = false;
            break;
          }
        }
        if (pos)
          boq_no++;
        i = j;
      } else
        i++;
    }

    return boq_no;
  }
  int minDays(vector<int> &bloomDay, int m, int k) {
    int low = 0, high = *max_element(bloomDay.begin(), bloomDay.end());

    int ans = -1;
    // Variable: day.
    // For range of days and fixed boq and flowers/boq
    // x x x x x x x | y y y y y y y
    //               | <all bloomed OR req sequence bloomed.>
    while (low <= high) {
      int mid = low + (high - low) / 2;
      if (possibleBoq(bloomDay, mid, k) >= m) {
        ans = mid;
        high = mid - 1;
      } else
        low = mid + 1;
    }

    return ans;
  }
};

int main() {
  vector<int> vec = {1, 10, 2, 3, 4, 9, 4, 8, 7, 5};
  solution s;
  cout << s.minDays(vec, 4, 2) << endl;
  return 0;
}
