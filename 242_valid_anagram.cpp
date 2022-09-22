/**
 * Use a single array containing 26 slots (one for each lowercase character). We start with all
 * 0 elements. We add one to the corresponding position when s has that character and take one
 * away when t has that character. If any slot is not equal to zero, not an anagram.
 */
#include <string>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        int counts[26] = {};
        
        for (int i = 0; i < s.length(); i++) {
            counts[s[i]-'a']++;
            counts[t[i]-'a']--;
        }
        
        for (int j = 0; j < 26; j++) {
            if (counts[j] != 0) {
                return false;
            }
        }
        
        return true;
    }
};