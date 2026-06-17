#include<iostream>
#include<vector>

using namespace std;

// This is the bruteforce recursion. 
// It exits early if found.
// But if not found, it WILL explore all 2^n cases : That will cause TLE for sure.
// This needs DP optimization.
class Solution {
  public:
  
  
    bool doesExist(vector<int>& arr, int currPos, int subseq_sum, int target){
        if(currPos == arr.size()){
            return false;
        }
        
        else if (target == (subseq_sum + arr[currPos]) ) return true; // No need to check 
        // any more subsequence
        
        // Now recursive call.
        
        bool found = doesExist(arr, currPos + 1, subseq_sum + arr[currPos], target);
        
        // Only if found is false: ie not equals target
        if(!found) found = doesExist(arr, currPos + 1, subseq_sum, target);
        
        return found;
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        return doesExist(arr, 0, 0, k);
    }
};