/**
 * O(n^2) algorithm that times out! Couldn't get the optimal solution myself sadly.
 */
class SolutionBad {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int prod = 1;

            for (int j = 0; j < nums.size(); j++) {
                prod *= i == j ? 1 : nums[j];
            }
            res.push_back(prod);
        }

        return res;
    }
};

/**
 * Came up with this one after reading a description of the optimal solution.
 * 
 * O(n) but still rather slow compared to the optimal solution below.
 */
class SolutionBetter {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        map<int, int> prefix;
        map<int, int> suffix;

        prefix[0] = 1;
        suffix[nums.size() - 1] = 1;

        for (int i = 1; i < nums.size(); i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }
        
        for (int i = nums.size() - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            res.push_back(prefix[i] * suffix[i]);
        }

        return res;
    }
};

/**
 * Couldn't figure this one out myself. Best solution at O(n) time and space
 */
class SolutionBest {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        for (int i = 1; i < n; i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int postfix = 1;

        for (int i = n - 1; i >= 0; i--) {
            res[i] = postfix * res[i];
            postfix *= nums[i];
        }

        return res;
    }
};