/**
 * Bit ugly but uses the two pointer approach to check from outwards
 * to inwards. If the two current outer characters don't match, it
 * is not a palindrome. If we get to the point where l<r, it is a real
 * palindrome.
 */
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s == "") {
            return true;
        }
        
        int l = 0;
        int r = s.length();
        
        while (l < r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            } else if (!isalnum(s[r])) {
                r--;
                continue;
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