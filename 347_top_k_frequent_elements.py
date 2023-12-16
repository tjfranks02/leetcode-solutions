class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> count;

        for (int num : nums) {
            count[num]++;
        }

        vector<vector<int>> buckets(n + 1);

        for (auto it = count.begin(); it != count.end(); it++) {
            buckets[it->second].push_back(it->first);
        }

        vector<int> res;

        for (int i = n; i > 0; i--) {
            if (res.size() >= k) {
                break;
            }
            
            if (!buckets[i].empty()) {
                res.insert(res.end(), buckets[i].begin(), buckets[i].end());
            }
        }

        return res;
    }
};