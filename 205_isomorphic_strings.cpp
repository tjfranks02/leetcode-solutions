/**
 * Isomorphic strings! Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * My solution is to use two maps to keep track of the characters in s and t. If the characters in s
 * and t are not seen before, then assign them a new id. If they are seen before, then check if the
 * ids are the same. If they are not, then return false. If they are the same, then continue.
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int seen_id = 1;
        map<char, int> s_seen;
        map<char, int> t_seen;

        for (int i = 0; i < s.length(); i++) {
            int s_existing = s_seen[s[i]];
            int t_existing = t_seen[t[i]];

            if (s_existing != t_existing) {
                return false;
            } else if (!s_existing) {
                s_seen[s[i]] = seen_id;
                t_seen[t[i]] = seen_id;
                seen_id++;
            }
        }

        return true;
    }
};