/*
Missing And Repeating

Difficulty: Easy      Accuracy: 24.83%      Submissions: 700K+      Points: 2
Average Time: 30m

Given an unsorted array arr[] of size n,
containing elements from the range 1 to n,
it is known that one number in this range is missing,
and another number occurs twice in the array,
find both the duplicate number and the missing number.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<int> findTwoElement(vector<int> &arr) {

    long int sumArr = 0, sumNat = 0, sumSquareArr = 0, sumSquareNat = 0;
    int dup_mis, dup_plus_mis;

    for (int i = 0; i <= arr.size() - 1; i++) {
      sumArr = sumArr + arr[i];
      sumNat = sumNat + i + 1;
      sumSquareArr = sumSquareArr + (arr[i] * arr[i]);
      sumSquareNat = sumSquareNat + (i + 1) * (i + 1);
    }

    dup_mis = sumArr - sumNat;
    dup_plus_mis = (sumSquareArr - sumSquareNat) / dup_mis;
    return {(dup_plus_mis + dup_mis) / 2, (dup_plus_mis - dup_mis) / 2};
  }
};
