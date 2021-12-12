/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

Find and return the maximum profit you can achieve.

*/

/*
Consider the vector of prices as a graph.
In order to get the maximum profit of the stock, we need to consider every time
the stock increases in value. 
If we iterate through the array and find every place where the stock increases in value,
(this is where prices[i - 1] < prices[i]) 
and simply find the difference between each and take the sum of all these differences that
exist in the array, it gives you the maximum profit. 
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            if (i > 0 && prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};