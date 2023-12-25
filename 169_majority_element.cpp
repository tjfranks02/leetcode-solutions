/**
 * Fairly space-inefficient solution using a map. The problem statement says it can be done in
 * O(1) space so let's give it anonther try.
 */
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        
        for (int num : nums) {
            count[num]++;
        }

        int max_count = INT_MIN;
        int max_elem = INT_MIN;

        for(auto it = count.begin(); it != count.end(); ++it) {
            if (it->second > max_count) {
                max_count = it->second;
                max_elem = it->first;
            }
        }

        return max_elem;
    }
};