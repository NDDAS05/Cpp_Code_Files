#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // In this case we will again use tabulation
        // We can either take or leave the current house.

        // (This is house robber 1)

        // Say 1--3--4--5--1--7
        // 1(1)--3--4--5--1--7
        // 1(1)--3(3)--4--5--1--7 
        // At 4: I can either take money of two stages back(1) and combine with current stage (4) to make 5 upto 4.
        // OR, I can keep money from stage 3 and not rob the current one.
        // Which one is greater? 5 or 3 : 5
        // So, 1(1)--3(3)--4(5)--5--1--7

        // Same: at 5 either 4(5) or combine with 3
        // So 8(5+3) or 5? 8
        //1(1)--3(3)--4(5)--5(8)--1--7

        // At 1: combine with either max upto 4: 5+1 = 6 or keep max upto 5(8) and not rob 1.
        // So, 1(1)--3(3)--4(5)--5(8)--1(8)--7 

        // Similarly at 7:
        // 1(1)--3(3)--4(5)--5(8)--1(8)--7(15)

        // Now at house robber 2: We have last house connected to first one. So if we take first house, can not rob last one.
        // If we start from 2nd house can rob last one.

        // If we skip i=2 house, we have taken first one so last can't be robbed.
        // If we do take i=1 (that is skip 1 and 3), we can include last one.
        int size = nums.size();

        vector<int> dp(size); // In tabulation method we do not require to init with -1 as we do not do any -1 checking in loop.
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i=2; i<size; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }

        int last_excluded = dp[size-2];

        // Now similarly we can count from backwards and exclude the first one
        // Atp we know array size is atlest 3.
        dp[size-1] = nums[size-1];
        dp[size-2] = max(nums[size-2], nums[size-1]);

        // Traversing from back
        for(int i=size-3; i>=0; i--){
            dp[i] = max(dp[i+1], nums[i]+dp[i+2]);
        }
        int first_excluded = dp[1];

        return max(first_excluded, last_excluded);
    }
};