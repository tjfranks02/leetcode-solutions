/**
 * Very easy 2 pointer problem which I solved nice and quick!
 * 
 * Time complexity: O(n), Space complexity: O(1) (in-place)
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l = 0, r = s.size() - 1;

        while (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;

            l++; r--;
        }
    }
};