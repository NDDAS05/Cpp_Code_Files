// What should dp represent?
// dp[i] : Starting from index i, the string CAN be divided in such a way that all the segments are in dictionary. 
// So For a certain index if we get findStr = true, that means we will store that in dp saying starting from this index a successful partition is possible.

// We shall check this dp array before entering loop.

class Solution {
    bool findStr(int i, string& s, unordered_set<string>& ust, vector<int>& dp){
        if(i>=s.length()) return true;
        else if(dp[i]!=-1) return dp[i];


        for(int j=i; j<s.length(); j++){
            string str= s.substr(i, j-i+1);
            if(ust.count(str) && findStr(j+1, s, ust, dp)){
                if(j+1 < s.size()) dp[i] = 1; // Not j+1. This loop made sure that starting at index i, segmentation possible.
                // This will be recursively true for all the future segments.
                return true;
            }
        }

        dp[i] = 0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> ust(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        // -1: not computed yet
        // 0: starting from this "i" index no way to divide the string in such a way that its segments are available in dictionary.
        // 1: possible to find
        return findStr(0, s, ust, dp);
    }
};