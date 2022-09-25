/**
 * Two pointer approach. One on each side of the array to begin with.
 * Check the middle element
 *   1. If smaller than target, move l to mid + 1
 *   2. If bigger than target, move r to mid - 1
 *   3. If equal to target, return index as we have found our answer
 */
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + floor((r - l) / 2);
            
            if (nums[mid] == target) {
                return mid; 
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        
        return -1;
    }
};