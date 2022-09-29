/**
 * Dynamic programming solution. Keep track of the maximum amount you can rob
 * that is at least 1 away from the current index. Keep on updating this amount
 * until you reach the end.
 */
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int curr_max = nums[0];
        int prev_max = nums[1];
        int curr_max_tmp;
        
        for (int i = 2; i < nums.size(); i++) {
            curr_max_tmp = curr_max;
            curr_max = max(curr_max, prev_max);
            prev_max = curr_max_tmp + nums[i];
        }
        return max(curr_max, prev_max);
    }
};