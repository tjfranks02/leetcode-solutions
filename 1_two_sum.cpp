/**
 * Use a map to store all the numbers that have been seen so far.
 * If a number's complement is found in the map, return the two indices,
 * otherwise keep looping.
 * 
 * Since we can assume that there is always exactly one answer, this will
 * always return the correct pair.
 */
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> diff;
        vector<int> returnPair;
        
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int needed = target - num;
            
            if (diff.count(needed)) {
                returnPair.push_back(diff[needed]);
                returnPair.push_back(i);
                break;
            } else {
                diff.insert({num, i});
            }
        }
        return returnPair;
    }
};