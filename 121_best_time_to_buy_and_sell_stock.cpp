/**
 * Two pointer approach with both starting at index 0. If we find a
 * lower point, set it as the time to sell. If we find a higher price,
 * set the new highest price.
 */
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 0;
        int maxP = 0;        
        
        while (r < prices.size()) {
            if (prices[r] < prices[l]) {
                l = r;
            }
            maxP = max(maxP, prices[r] - prices[l]);
            r += 1;
        }  
        return maxP;
    }
};