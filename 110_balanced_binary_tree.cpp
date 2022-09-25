/**
 * Recursive DFS approach inspired by neetcode.
 * 
 * Result starts off as true. We start by calling DFS on the root node. DFS returns the
 * height of the binary tree. If the height of the two sub-trees differs by more than 1,
 * set the result to false.
 */
#include <math.h>

using namespace std;

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
    
    bool isBalanced(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        bool res = true;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, bool& res) {
        if (!root) {
            return 0;
        }
        
        int l = dfs(root->left, res);
        int r = dfs(root->right, res);
        
        if (abs(l - r) > 1) {
            res = false;
        }
        
        return 1 + max(l, r);
    }
};