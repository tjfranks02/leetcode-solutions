class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q(begin(stones), end(stones));

        while (q.size() > 1) {
            int s1 = q.top(); q.pop();
            int s2 = q.top(); q.pop();

            if (s1 != s2) {
                q.push(s1 - s2);
            }
        }

        return q.size() == 1 ? q.top() : 0;
    }
};