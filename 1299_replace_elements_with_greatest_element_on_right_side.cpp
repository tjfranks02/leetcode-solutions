/**
 * My solution which I got without consulting the answer!
 * 
 * Space complexity is O(n) which I think can be improved to O(1).
 */
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n, -1);

        for (int i = n - 2; i >= 0; i--) {
            ans[i] = max(ans[i + 1], arr[i + 1]);
        }

        ans[n - 1] = -1;
        return ans;
    }
};

/**
 * here's one with O(1) space complexity and O(n) time complexity.
 * 
 */
class Solution2 {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int currMax = -1;
        int tmp = arr[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            currMax = max(tmp, currMax);
            tmp = arr[i];
            arr[i] = currMax;
        }
        arr[n - 1] = -1;
        return arr;
    }
};