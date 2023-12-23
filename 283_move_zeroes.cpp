/**
 * My slow O(n^2) solution to the problem. Can definitely be improved.
 */
class SlowSolution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();

        while (r < n) {
            while (l < n && nums[l] != 0) l++;
            r = l;

            while (r < n && nums[r] == 0) r++;

            if (r < n) {
                swap(nums[l], nums[r]);
                l++;
            }
        }
    }
};

/**
 * Woohoo O(n) (i think) with just a simple optimisation. Previously, r is set to l on each iteration
 * of the outer loop. This is unnecessary, since we know that r will always be >= l. So we can just
 * set r to max(r, l) instead.
 * 
 * 
 */
class FasterSolution {
public:
    void moveZeroes(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();

        while (r < n) {
            while (l < n && nums[l] != 0) l++;
            r = max(r, l);

            while (r < n && nums[r] == 0) r++;

            if (r < n) {
                swap(nums[l], nums[r]);
                l++;
            }
        }
    }
};