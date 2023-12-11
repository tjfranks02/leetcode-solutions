/**
 * Longest common prefix. Given an array of strings, return the longest common prefix that is shared 
 * amongst all strings. Note: you may assume all strings only contain lowercase alphabetical characters.
 * 
 * My approach is to iterate through the array of strings and compare the first letter of each str.
 * Pretty simple.
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int longest = 0;
        int n = strs.size();

        if (n == 1) {
            return strs[0];
        }

        while (true) {
            int curr = 0;

            while (curr < n - 1) {
                if (longest >= strs[curr].length() || 
                  strs[curr][longest] != strs[curr + 1][longest]) {
                    return strs[curr].substr(0, longest);
                }
                curr++;
            }

            longest++;
        }

        return strs[0];
    }
};