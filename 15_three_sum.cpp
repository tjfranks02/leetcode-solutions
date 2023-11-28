/**
 * My dodgy and slow solution which i coded up after seeing a text description of the answer...
 * Was so close to getting it but was impatient!
 */
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        set<string> seen;
        vector<vector<int>> res;

        int i = 0, j = 1, k = nums.size() - 1;

        while (j < k) {
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    if (!seen.contains(to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]))) {
                        res.push_back(vector<int>({ nums[i], nums[j], nums[k] }));
                        seen.insert(to_string(nums[i]) + to_string(nums[j]) + to_string(nums[k]));
                    }
                    j++;
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }

            i++;
            j = i + 1;
            k = nums.size() - 1;
        }

        return res;
    }
};

/**
 * Okay this is the optimal solution that I couldn't work out. It's O(n^2) time and O(1) space.
 * 
 * Instead of keeping track of what we've already seen with a map, this one keeps on iterating if
 * it detects that the same solution will be added with the current combination.
 */
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        int i = 0, j = 1, k = nums.size() - 1;

        for (int i = 0; i < nums.size() - 2; i++) {

            if (nums[i] > 0) {
                break;
            }

            if (i > 0 && nums[i - 1] == nums[i]) {
                continue;
            }

            j = i + 1;
            k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    res.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    while (j < k && nums[j] == nums[j + 1]) {
                        j++;
                    }
                    j++;

                    while (j < k && nums[k] == nums[k - 1]) {
                        k--;
                    }
                    k--;
                } else if (sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return res;
    }
};