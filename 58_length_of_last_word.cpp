/**
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return 
 * the length of last word (last word means the last appearing word if we loop from left to right) 
 * in the string. 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int letterSeen = false;
        int length = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                letterSeen = true;
                length++;
            } else if (letterSeen && s[i] == ' ') {
                return length;
            }
        }

        return length;
    }
};