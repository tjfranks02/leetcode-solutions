/*
Problem: Return whether s is a palindrome. Ignore non-alphanumeric characters and case.

Solution: Use two pointers, one at the beginning and one at the end. Increment the left pointer
until it reaches an alphanumeric character. Decrement the right pointer until it reaches an
alphanumeric character. If the characters at the two pointers are not equal, return false.
If we reach the point where l >= r, return true.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0; 
        int r = s.length() - 1;

        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                l++;
            }

            while (r > l && !isalnum(s[r])) {
                r--;
            }

            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};