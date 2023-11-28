class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int curr = numbers[l] + numbers[r];

            if (curr == target) {
                return vector<int>({l + 1, r + 1});
            }

            if (curr < target) {
                l += 1;
            } else {
                r -= 1;
            }
        }

        return vector<int>({-1, -1});
    }
};