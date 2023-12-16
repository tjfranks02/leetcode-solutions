class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int back_2 = cost[0]; 
        int back_1 = cost[1];
        int curr_min = min(back_1, back_2);

        for (int i = 2; i < cost.size(); i++) {
            curr_min = cost[i] + min(back_1, back_2);
            back_2 = back_1;
            back_1 = curr_min;
        }

        return min(back_1, back_2);
    }
};