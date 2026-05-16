#include <bits/stdc++.h>
using namespace std;

/*
 * APPROACH: Prefix XOR + Hash Map
 * ---------------------------------------------------------
 * 1. The goal is to find subarrays where XOR(i, j) == k.
 * 2. Using the property: if XOR(0, j) is 'curr_xor' and XOR(0, i-1) is
'prefix_xor',
 *    then XOR(i, j) = curr_xor(0-j) ^ prefix_xor(0-i-1).
 * 3. We need: curr_xor ^ prefix_xor == k.
 * 4. Rearranging for the unknown: prefix_xor = curr_xor ^ k.
 *
 * ALGORITHM:
 * - Initialize 'count' to 0 and 'curr_xor' to 0.
 * - Maintain a Hash Map (map<int, int>) to store frequencies of prefix XORs.
 * - Pre-fill map[0] = 1 (to handle subarrays starting from index 0).
 * - Iterate through the array:
 *     a. Update 'curr_xor' by XORing with the current element.
 *     b. Calculate 'target' = curr_xor ^ k.
 *     c. If 'target' exists in the map, add its frequency to 'count'.
 *     d. Increment the frequency of 'curr_xor' in the map.
 * - Return 'count'.
 *
 * Complexity: Time O(N), Space O(N)

 |------- p ------|
  A    B    C    D    E
 |---- q ---| r  |

Say target = 6.
We want to make r = 6 (r is an arbitrary sub-ARRAY cuz of variable endpoint of
q) so we have preXor = p. We know for ans "r" got to be 6. So we, from map, find
how many ways to get remaining ( p ^ r ) i.e. (p ^ 6). If q = p^6, then only p ^
q = r = 6
 */

class Solution {
public:
  // Function to count subarrays with given XOR
  int countSubarrays(vector<int> &A, int k) {
    // Store frequency of prefix XORs
    unordered_map<int, int> freq;
    // Initialize with prefix XOR 0
    freq[0] = 1;

    // Current prefix XOR
    int preXor = 0;
    // Answer count
    int count = 0;

    // Traverse array
    for (int num : A) {
      // Update prefix XOR
      preXor ^= num;

      // Compute required XOR
      int rem = preXor ^ k;

      // If target exists in map, add its frequency
      if (freq.find(rem) != freq.end()) {
        count += freq[rem];
      }

      // Store current prefix XOR in map
      freq[preXor]++;
    }
    return count;
  }
};

int main() {
  vector<int> A = {4, 2, 2, 6, 4};
  int k = 6;
  Solution sol;
  cout << sol.countSubarrays(A, k) << endl;
  return 0;
}
