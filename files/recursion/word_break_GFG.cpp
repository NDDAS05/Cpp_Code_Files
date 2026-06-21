#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength; // stores the maximum length of any word in the dictionary

    // Recursive helper function with memoization
    bool isPossible(int startIdx, string &s, unordered_set<string>& S, vector<int>& dp) {
        // Base case: if we've reached or passed the end of the string,
        // it means all previous partitions were valid words.
        if (startIdx >= s.length()) return true;

        // Memoization check:
        // If we've already solved this subproblem (starting at startIdx),
        // return the stored result immediately.
        if (dp[startIdx] != -1) return dp[startIdx];

        // Try all possible substrings starting at startIdx
        for (int i = startIdx; i < s.length(); i++) {
            // Optimization: if substring length exceeds the longest dictionary word,
            // no need to check further (prunes the search space).
            if (i - startIdx + 1 > maxLength) break;

            // Extract substring from startIdx to i
            string word = s.substr(startIdx, i - startIdx + 1);

            // If this substring exists in the dictionary
            if (S.find(word) != S.end()) {
                // Recursively check if the rest of the string can be broken
                if (isPossible(i + 1, s, S, dp)) {
                    // If yes, mark this startIdx as solvable and return true
                    dp[startIdx] = 1;
                    return true;
                }
            }
        }

        // If no valid partition was found, mark this startIdx as unsolvable
        dp[startIdx] = 0;
        return false;
    }

    bool wordBreak(string &s, vector<string> &dictionary) {
        // dp[i] represents whether substring starting at index i
        // can be broken into valid dictionary words.
        // -1 = not computed yet, 1 = true, 0 = false
        vector<int> dp(s.length(), -1);

        // Store dictionary words in a set for O(1) lookup
        unordered_set<string> S;
        maxLength = 0; // initialize maxLength

        for (auto &str : dictionary) {
            S.insert(str);
            maxLength = max(maxLength, (int)str.length());
        }

        // Start recursion from index 0
        return isPossible(0, s, S, dp);
    }
};
