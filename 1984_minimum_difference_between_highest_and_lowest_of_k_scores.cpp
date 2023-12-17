/**
 * Minimum Difference Between Highest and Lowest of K Scores
 * 
 * Solution where I sort the array and then use a sliding window to find the minimum
 * spread between k scores. Matches the solution given by neetcode! Got this one myself yay!
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if (n < k) {
            return nums[0] - nums[n - 1];
        }

        int l = 0;
        int r = k - 1;
        int min_spread = INT_MAX;

        while (r < n) {
            min_spread = min(min_spread, nums[r] - nums[l]);
            l++;
            r++;
        }

        return min_spread;
    }
};