class Solution {
public:
    bool isValid(string s) {
        set<char> open = {'[', '{', '('};
        map<char, char> openToClose = {{')', '('}, {']', '['}, {'}', '{'}};
        stack<char> seen;

        for (auto c : s) {
            if (open.contains(c)) {
                seen.push(c);
            } else if (!seen.empty() && openToClose[c] == seen.top()) {
                seen.pop();
            } else {
                return false;
            }  
        }

        return seen.empty();
    }
};