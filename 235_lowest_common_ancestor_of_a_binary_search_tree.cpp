/**
 * Simple recursive solution. If both p and q and less than the root, keep checking the left branch.
 * If both p and q are greater than the root, keep checking the right branch. Otherwise, return the
 * root as they are on either side of it so the root must be the greatest common ancestor.
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val and q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val and q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
        
        return nullptr;
    }
};