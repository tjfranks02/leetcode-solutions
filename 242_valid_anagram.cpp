/*
Problem: Return whether t is a valid anagram of s

Solution: Use two maps to keep track of the number of times each character appears in s and t. 
If the maps are equal at the end, return true. Otherwise, return false.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> count_s;
        map<char, int> count_t;

        for (int i = 0; i < s.length(); i++) {
            if (count_s.find(s[i]) == count_s.end()) {
                count_s[s[i]] = 1;
            } else {
                count_s[s[i]] += 1;
            }

            if (count_t.find(t[i]) == count_t.end()) {
                count_t[t[i]] = 1;
            } else {
                count_t[t[i]] += 1;
            }
        }

        return count_s.size() == count_t.size() && equal(count_s.begin(), count_s.end(), count_t.begin());
    }
};

/**
 * Slightly better. Takes advantage of the fact that the values of everything in a map are initially
 * 0. So we can just increment the value of the key by 1, avoiding the if statements.
 * 
 * Time complexity: O(n)
 * Space complexity: O(n)
*/
class Solution2 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> count_s;
        map<char, int> count_t;

        for (int i = 0; i < s.length(); i++) {
            count_s[s[i]] += 1;
            count_t[t[i]] += 1;
        }

        return count_s.size() == count_t.size() && equal(count_s.begin(), count_s.end(), count_t.begin());
    }
};

/**
 * Even more compact. First, increment the count of each character in t. Then, decrement the count of
 * characters in s. If the remaining count has anything not equal to 0, return false, otherwise true.
*/
class Solution3 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        map<char, int> count;

        for (auto x : t) {
            count[x] += 1;
        }

        for (auto x : s) {
            count[x] -= 1;
        }

        for (auto x : count) {
            if (x.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};