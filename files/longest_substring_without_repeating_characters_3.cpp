#include <bits/stdc++.h>
#define endl std::endl

class Solution1_best {
public:
  int lengthOfLongestSubstring(std::string s) {
    // Instead of hash map, array is to be used
    std::vector<int> arr(
        256, -1); //-1 means not yet found //If not -1, array's --ASCII-th--
                  // index will store --string-- position where last time found.
    int l = 0, r = 0, maxlen = 1, windowLen = 0, size = s.length();
    if (size == 0)
      return 0;

    while (r < size) {
      // Case 1 not found already or found behind l
      if (arr[s[r]] == (-1) || arr[s[r]] < l) {
        arr[s[r]] = r;
      } else {
        // Dup is found: Then setting l to arr[index]+1 and setting last seen of
        // dup element to current r.
        l = arr[s[r]] + 1;
        arr[s[r]] = r;
      }
      windowLen = r - l + 1;
      maxlen = std::max(maxlen, windowLen);
      r++;
    }
    return maxlen;
  }
};

class Solution2_HashMapTax {
public:
  int lengthOfLongestSubstring(std::string s) {
    int l = 0, r = 0, maxlen = 1, winlen = 0,
        size = s.length(); // If string is empty which is as per constraints
                           // allowed, will be straight up returned
    // edge case: 0 input, 1 size input
    std::unordered_map<char, int> mp;
    mp[s[r]] = 0;
    if (size == 0)
      return 0;
    while (r < size) {
      // Logic first, then increment.
      // For current element
      // If does not exist in hash map OR exists but index lower than* l: Then
      // add them
      if (mp.find(s[r]) == mp.end() || mp[s[r]] < l) {
        // In this case insert key into map
        mp[s[r]] = r;
      }

      else { // Key exists or dup exists: Then update to current duplicate
             // location.
        l = mp[s[r]] + 1;
        mp[s[r]] = r; // Updated to new index
      }

      winlen = r - l + 1;
      maxlen = std::max(maxlen, winlen);
      r++;
    }

    return maxlen;
  }
};

class Solution3_InitialBruteForce {
public:
  int lengthOfLongestSubstring(std::string s) {
    int l = 0, r = 0, maxlen = 1, winlen = 0,
        size = s.length(); // If string is empty which is as per constraints
                           // allowed, will be straight up returned

    if (size == 0)
      return 0;
    std::unordered_map<char, int> mp;
    mp[s[r]] = 0;

    while (r < size - 1) {
      r++; // Increasing r to check if the new character exists or not
      if (mp.find(s[r]) != mp.end()) { // Thus duplicates exist
        while (l < mp[s[r]]) {
          mp.erase(s[l]);
          l++;
        }
        mp[s[r]] = r;
        l++;
      } else { // New element: Put into unordered map
        mp[s[r]] = r;
      }

      winlen = r - l + 1;
      maxlen = std::max(maxlen, winlen);
    }
    return maxlen;
  }
};
int main() {
  int n1, n2, n3;
  Solution1_best s1;
  Solution2_HashMapTax s2;
  Solution3_InitialBruteForce s3;
  std::string str = "aubucbuduebudkgjldkguuu";
  n1 = s1.lengthOfLongestSubstring(str);
  std::cout << n1 << endl;
  n2 = s2.lengthOfLongestSubstring(str);
  std::cout << n2 << endl;

  n3 = s3.lengthOfLongestSubstring(str);
  std::cout << n3 << endl;

  return 0;
}
