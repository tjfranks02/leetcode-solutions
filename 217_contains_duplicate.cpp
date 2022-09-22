/*
* Uses a set. Loops through each element in nums and inserts it into the set.
* If element is already in the set, return true. False if we get to the end.
*
* Time: O(n)
* Memory: O(n)
*/
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> seen;
        
        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != seen.end()) {
                return true;
            } else {
                seen.insert(nums[i]);
            }
        }
        return false;
    }
};