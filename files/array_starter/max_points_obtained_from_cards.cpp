#include <algorithm>
#include <iostream>
#include <vector>

#define endl std::endl

class solution {
public:
  int maxScore(std::vector<int> &cardPoints, int k) {

    size_t size = cardPoints.size(); // array size
    int totalsum = 0, sum = 0, minsum;
    for (int i : cardPoints) {
      totalsum += i;
    }
    if ((size_t)k == size)
      return totalsum;
    size_t l = 0,
           r = size - k -
               1; // Minimizing window sum to make rest part maximum, here 3

    for (size_t i = l; i <= r; i++) {
      sum += cardPoints[i]; // Initial Window sum
    }
    minsum = sum; // VVI, if initialized with INT_MAX, in the first comparison,
                  // it would have skipped initial window sum as the window
                  // begins by advancing the window

    while (r < size - 1) {
      // minsum=std::min(sum, minsum) --If minsum initialized with INT_MAX
      // instead of initial window sum
      sum = sum - cardPoints[l];
      l++;
      r++;
      sum = sum + cardPoints[r];
      minsum = std::min(sum, minsum);
    }

    return (totalsum - minsum);
  }
};

int main() {
  solution s1;
  std::vector<int> vec = {9, 7, 7, 9, 7, 7, 9};
  int soln = s1.maxScore(vec, 7);
  std::cout << soln << endl;
  return 0;
}
