/**
 * Remove all elements with value val in-place and return the new length.
 * 
 * Stole this one from neetcode! Had the right idea but couldn't quite figure it out.
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != val) {
                swap(nums[i], nums[count]);
                count++;
            }
        }

        return count;
    }
};