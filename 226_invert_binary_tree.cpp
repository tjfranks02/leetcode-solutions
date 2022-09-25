/**
 * Recursive solution.
 * Base case: when root is null return null.
 * Recursive case:
 *   Swap the left and right branches of the tree by calling invertTree recursively.
 */

/**
 * Representation of a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (!root) {
            return nullptr;
        }
        
        TreeNode* tmpLeft = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpLeft);
        return root;
    }
};