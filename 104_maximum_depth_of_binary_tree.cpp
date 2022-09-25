/**
 * Recursive solution.
 * Base case: When root is null, return 0
 * Recursive case: return 1 + the maximum height of the left and right branches.
 * 
 * Quite fast as each node need only be visited once.
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
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};