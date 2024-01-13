/**
 * Inefficient solution to the problem. But it's mine at least!
*/
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        map<int, int> nextGreater;

        for (int i = 0; i < nums1.size(); i++) {
            int nextGreater = -1, index = -1;

            for (int j = 0; j < nums2.size(); j++) {
                if (nums2[j] == nums1[i]) {
                    index = j;
                }
            }

            for (int j = index; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];
                    break;
                }
            }

            res.push_back(nextGreater);
        }

        return res;
    }
};