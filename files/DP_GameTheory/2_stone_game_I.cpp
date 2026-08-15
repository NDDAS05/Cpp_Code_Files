// Almost like predict the winner.

class Solution {
    int gameScore(int i, int j, vector<vector<int>>& dp, vector<int>& piles){
        if(i>j || i<0 || j>=piles.size()) return 0;
        else if(i==j) return piles[i];
        else if(dp[i][j]!= -1) return dp[i][j];
        int take_ith = piles[i] + min(gameScore(i+2, j, dp, piles), gameScore(i+1, j-1, dp, piles));
        int take_jth = piles[j] + min(gameScore(i+1, j-1, dp, piles), gameScore(i, j-2, dp, piles));

        return dp[i][j] = max(take_ith, take_jth);


    }
public:
    bool stoneGame1(vector<int>& piles) {
        int totalPts = 0;
        for(int& i: piles) totalPts+=i;
        vector<vector<int>> dp(piles.size(), vector<int>(piles.size(), -1)); // O(N^2)
        int alice = gameScore(0, piles.size()-1, dp, piles);
        
        return alice > (totalPts - alice);
    }
    bool stoneGame(vector<int>& piles){
        // In this game there are some important rules as per question:
        // 1. There are even no of piles.
        // 2. Total number of stones is odd, so no ties.

        // Now, alice can take a--b--c--d... some of the ways are..
        // In: 1) a---[b taken]--d--[c taken]
        // 2) a---[b taken]--c--[d taken] <---------- [or a--[d taken]---c---[b taken]]
        // 3) d---[a taken]--b---[c taken] <--------- [or d--[c taken]--b--[a taken]]
        // [This can be extended to larger piles as well]

        // Now since there are no ties, the sum of last two options (a,c) OR (b,d) will never be same. Since alice has a option to pick in the alternating manner too, she can chose whichever combination gives highest total point. [alice taking alternate forces bobs piles to be alternate as well].

        // And the alternate pile sum will never be the same as per given constraint.
        // So one pile ALWAYS has more stone than other pile: which can be chosen to Force lesser sum alternating pile on opponent and therefore win.
        /*
        There are an even number of piles. Alice can force herself to take either all even-indexed piles or all odd-indexed piles. The sums of these two groups add up to the total number of stones. Since the total is odd, the two sums cannot be equal. Therefore one group has strictly more stones than the other. Alice can choose the strategy that guarantees her the larger group, so she must win.
        */
        // Thus the answer is true always.

        return true;
    }
};  