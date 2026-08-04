class Solution {
public:
    int rob(vector<int>& nums) {
        // Say array is 9--1--2--99--4--3
        // If at 9 we can max obtain 9
        // 9(9)---1---2---99---4---3

        // At 1, we have only access to 1 as we can not get 9 
        // So, 9(9)---1(1)---2---99---4---3

        // At 2, we can not access 1 but can access previous 9.
        // So 9(9)---1(1)---2(11)---99---4---3

        // Now at 99.
        // Either we combine 99 with 1s max money (100)
        // Or with 9s max money (108)
        // Clearly we can not combine 99 with max money at 2
        // So, 9(9)---1(1)---2(11)---99(108)---4---3

        // At 4
        // We can combine with 2 (which already includes best possible money till 2) or 1 (which already includes best possible earning till 1)

        // SO, 9(9)---1(1)---2(11)---99(108)---4(15)---3

        // At 3
        // We can combine with 9s money (111) or 2s money(11)
        // 9(9)---1(1)---2(11)---99(108)---4(15)---3(111)

        // So what is the best possible earning? 
        // Max of earnings at all step that is 111 here.
        // So a tabulation approach should work here.
        int size = nums.size();
        if(size == 0) return 0;
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0], nums[1]);
        if(size == 3) return max(nums[0]+nums[2], nums[1]);

        vector<int> dp(size, -1);
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0]+nums[2];
        int maxEarn = max(dp[1], dp[2]);
        for(int i=3; i<size; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-3]+nums[i]);
            maxEarn = max(dp[i], maxEarn);
        }

        return maxEarn;

    }
};