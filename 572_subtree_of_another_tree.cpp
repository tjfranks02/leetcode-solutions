/**
 * Simple recursive solution. Check if the root and subTree are the same tree. If yes, return true.
 * If no, check if root.left == subRoot or root.right == subRoot.
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
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) {
            return true;
        }
        
        if (!root or !subRoot or root->val != subRoot->val) {
            return false;
        }
        
        return sameTree(root->left, subRoot->left) and sameTree(root->right, subRoot->right);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root and !subRoot) {
            return true;
        }
        
        if (!root or !subRoot) {
            return false;
        }
        
        return sameTree(root, subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};