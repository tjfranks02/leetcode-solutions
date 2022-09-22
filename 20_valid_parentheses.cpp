/**
 * The idea is that if you open a bracket, it must have a corresponding opening bracket
 * that was encountered most recently.
 */
#include <map>
#include <stack>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stck;
        
        map<char, char> mapping = {
            {')', '('}, 
            {'}', '{'},
            {']', '['}
        };
        set<char> opens = set<char> {'(', '{', '['};
        
        for (int i = 0; i < s.length(); i++) {
            if (opens.count(s[i])) {
                stck.push(s[i]);
            } else if (stck.empty() or mapping[s[i]] != stck.top()) {
                return false;
            } else {
                stck.pop();
            }
        }
        return stck.empty();
    }
};