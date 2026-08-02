/*
    GFG One:
    Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the last stair. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the last stair.


    Input: heights[] = [20, 30, 40, 20]
    Output: 20
    Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
    jump from stair 0 to 1: cost = |30 - 20| = 10
    jump from stair 1 to 3: cost = |20 - 30| = 10
    Total Cost = 10 + 10 = 20
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
    int cost(int n, vector<int>& height, vector<int>& dp){
        if(n<=0) return 0;
        if(n==1) return std::abs(height[0] - height[1]);
        if(dp[n]!= -1) return dp[n];
        
        // Now calculate the min cost to reach current step
        dp[n] = std::min((cost(n-1, height, dp) + std::abs(height[n] - height[n-1])), (cost(n-2, height, dp) + std::abs(height[n]- height[n-2])));
    
        return dp[n];
    }
  public:
    int minCost(vector<int>& height) {
        vector<int> dp(height.size(), -1); // Contains min cost at that step.
        return cost(height.size()-1, height, dp);
    }
};