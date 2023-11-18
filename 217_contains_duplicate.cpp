/*
Task: Return whether the given vector contains duplicate elements or not

Solution: Use a set to keep track of the elements seen so far. If we see an element that is already 
in the set, return true. Otherwise, return false.
*/
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;

        for (int num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
};