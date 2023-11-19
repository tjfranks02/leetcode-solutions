/**
 * Problem: Return the indices of the two numbers that add up to target assuming there is always
 * exactly one solution.
 * 
 * Solution: Use a map to keep track of the numbers we've seen so far. For each new number, check
 * if there is something in the map that adds up to the target. If there is, return the indices.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> seen;

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];

            if (seen.find(diff) != seen.end()) {
                return {seen.find(diff)->second, i};
            } else {
                seen.insert(pair<int,int>(nums[i], i));
            }
        }

        return {-1, -1};
    }
};