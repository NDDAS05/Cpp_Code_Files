/*
122. Best Time to Buy and Sell Stock II

You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

Find and return the maximum profit you can achieve.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Say: 0 based day indexing.
        // We calculate starting from day 1 as day 0 can not make profit more than 0

        // Since we can buy as many as (never holding more than 1 active stock) we want, we can buy whenever we see a "peak". 1(buy)---5(sell->buy)---7(sell) is same as 1----7.
        // So we keep a pointer "last_bought". That points to the record that we "might" buy.
        
        // last bought -> lb

        // Logic: We start from day 1. lb points to day 0. 

        // If prices[lb] < prices[day1] : We can buy lb and sell on day 1. Profit: prices[day1] -prices[lb]. We move lb to day 1 (As buying on day 0 and selling at higher price on day x is same as buying on day 0, making a small profit on day 1 then buying on day 1 again then selling on day x. Its a linear addition only.)

        // Since we "might" sell on day 1 again, lb is moved to day1 from day0.

        // Now on day 2 if price[day2] < price[day1], that means we can not make a small profit here. But since day2 is lower, we may buy on that day and may get a day later on that has higher price. So we move lb to day 2 - without any calculation. 

        // lb marks the day we "might" buy ,depending on current day price.

        int dayNo = prices.size();

        if(!dayNo) return 0;

        int lb = 0;
        int profit_till_day_i = 0;

        for(int i=1; i<dayNo; i++){
            if(prices[lb] < prices[i]){
                // We make a small profit here
                profit_till_day_i += (prices[i] - prices[lb]);
                lb=i; // We might buy today again.
                continue;
            }
            lb=i;
        }

        return profit_till_day_i;
    }
};