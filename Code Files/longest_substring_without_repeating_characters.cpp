#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#define endl std::endl

class Solution {
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
  int n;
  Solution s;
  std::string str = "abcabcabvffffffk";
  n = s.lengthOfLongestSubstring(str);
  std::cout << n << endl;
  return 0;
}
