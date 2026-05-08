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
    bool DFS(TreeNode* root, long left, long right)
    {
        if (root == NULL)
        {
            return true;
        }

        if (!(left < root->val && right > root->val))
        {
            return false;
        }

        return DFS(root->left, left, root->val) && DFS(root->right, root->val, right);
    }
public:
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }

        return DFS(root, LONG_MIN, LONG_MAX);
    }
};
