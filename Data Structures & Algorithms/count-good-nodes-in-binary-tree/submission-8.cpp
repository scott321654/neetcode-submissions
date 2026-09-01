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
    int dfs(TreeNode* root, int max_val) {
        if (!root) return 0;
        int res = (root->val >= max_val) ? 1 : 0;
        max_val = max(max_val, root->val);
        res += dfs(root->left, max_val);
        res += dfs(root->right, max_val);

        return res;
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
