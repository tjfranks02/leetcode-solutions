class Solution {
public:
    int hammingCount(int n) {
        int count = 0;

        while (n > 0) {
            count += n % 2;
            n /= 2;
        }

        return count;
    }

    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            ans[i] = hammingCount(i);
        }

        return ans;
    }
};

class Solution2 {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};
}