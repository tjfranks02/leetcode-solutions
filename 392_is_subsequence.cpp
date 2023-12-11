/**
 * Fast and dodgy solution which I came up with by myself.
 * 
 * Time complexity: O(n)
 * Space complexity O(1)
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sIndex = 0;
        int tIndex = 0;
    
        while (sIndex < s.length() && tIndex < t.length()) {
            if (s[sIndex] == t[tIndex]) {
                if (sIndex == s.length()) {
                    return true;
                }
                sIndex++;
            }
            tIndex++;
        }

        return sIndex == s.length();
    }
};