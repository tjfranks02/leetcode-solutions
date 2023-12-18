/**
 * Merge 2 strings alternatively. e.g. "abc" and "pqr" -> "apbqcr".
 * 
 * My solution that I got right after some battling with string concatenation. Yay! Seems to be
 * optimal time complexity.
*/
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";

        int p1 = 0, p2 = 0;

        while (p1 < word1.length() && p2 < word2.length()) {
            result = result + word1[p1] + word2[p2];
            p1++;
            p2++;
        }

        if (p1 < word1.length()) {
            result += word1.substr(p1, word1.length() - 1);
        }

        if (p2 < word2.length()) {
            result += word2.substr(p2, word2.length() - 1);
        }

        return result;
    }
};