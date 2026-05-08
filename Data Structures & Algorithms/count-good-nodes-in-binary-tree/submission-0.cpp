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
    int DFS(TreeNode* root, int maxVal)
    {
        if (root == NULL)
        {
            return 0;
        }
        int ret = (root->val >= maxVal) ? 1 : 0;

        maxVal = max(root->val, maxVal);

        ret += DFS(root->left, maxVal);
        ret += DFS(root->right, maxVal);

        return ret;
    }
public:
    int goodNodes(TreeNode* root) 
    {
        return DFS(root, root->val);
    }
};
