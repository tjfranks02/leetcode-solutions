/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        return 1 + max(getDepth(root->left), getDepth(root->right));
    }   

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int diameter = getDepth(root->left) + getDepth(root->right);
        int leftDiam = diameterOfBinaryTree(root->left);
        int rightDiam = diameterOfBinaryTree(root->right);

        return max({diameter, leftDiam, rightDiam});
    }
};