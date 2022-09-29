/**
 * Dynamic programming solution. The cost to get to a particular step is the
 * minimum of the cost to get to the two previous steps.
 * 
 * Did it without neetcode solution :-)
 */
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n1 = cost[0];
        int n2 = cost[1];
        int n1_tmp;    
        
        for (int i = 2; i < cost.size(); i++) {
            n1_tmp = n1;
            n1 = n2;
            n2 = min(n2, n1_tmp) + cost[i];
        }
        
        return min(n1, n2);
    }
};