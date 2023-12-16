
/**
 * Recursive solution which I came up with all by myself. Can't be that impressive though since
 * the problem statement describes the recursive solution as trivial. 
 */
public:
    void helperInorderTraversal(TreeNode* root, vector<int>& sol) {
        if (!root) {
            return;
        }

        helperInorderTraversal(root->left, sol);
        sol.push_back(root->val);
        helperInorderTraversal(root->right, sol);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> sol;
        helperInorderTraversal(root, sol);

        return sol;
    }
};

/**
 * Iterative solution which I had to google! Similar to the iterative implementation of DFS.
 */
class SolutionIterative {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;
        stack<TreeNode*> stk;
        TreeNode* current = root;

        while (!stk.empty() || current != NULL) {
            while (current != NULL) {
                stk.push(current);
                current = current->left;
            }

            TreeNode* next = stk.top();
            traversal.push_back(next->val);
            stk.pop();
            current = next->right;
        }

        return traversal;
    }
};