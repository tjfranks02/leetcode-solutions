class Solution {
public:
    int climbStairsMemo(int n, map<int, int>& cache) {
        if (n == 0 || n == 1) {
            return 1;
        }

        if (cache[n]) {
            return cache[n];
        } else {
            cache[n] = climbStairsMemo(n - 1, cache) + climbStairsMemo(n - 2, cache);
        }

        return cache[n];
    }

    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        map<int, int> cache;

        return climbStairsMemo(n - 1, cache) + climbStairsMemo(n - 2, cache);
    }
};