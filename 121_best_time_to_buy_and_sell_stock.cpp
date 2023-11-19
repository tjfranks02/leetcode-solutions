/*
Problem: Return the maximum profit that can be made from buying and selling a stock. You can only
buy and sell once.

Solution: Keep track of the current maximum profit and the minimum price seen so far. If the current
price is less than the minimum price, update the minimum price. Otherwise, update the maximum profit
if the difference between the current price and the minimum price is greater than the current maximum
profit.
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 0;
        int curr_max = INT_MIN;

        while (r < prices.size()) {
            curr_max = max(curr_max, prices[r] - prices[l]);

            if (prices[r] < prices[l]) {
                l = r;
            }
            
            r++;
        }

        return curr_max;
    }
};