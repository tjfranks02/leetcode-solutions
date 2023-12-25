/**
 * Solution that I hadn to steal from the leetcode discussion section. I had a different idea but
 * it wouldn't have produced a balanced tree. Binary search is a weakness for sure!
 * 
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) { return nullptr; }
        if (nums.size() == 1) { return new TreeNode(nums[0]); }

        int mid = (nums.size()) / 2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        
        vector<int> leftNums(nums.begin(), nums.begin() + mid);
        vector<int> rightNums(nums.begin() + mid + 1, nums.end());

        root->left = sortedArrayToBST(leftNums);
        root->right = sortedArrayToBST(rightNums);

        return root;
    }
};