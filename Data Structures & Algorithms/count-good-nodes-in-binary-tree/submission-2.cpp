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

        int result = 0;
        if (maxVal <= root->val)
        {
            result = 1;
        }
        maxVal = max(maxVal, root->val);
        result += DFS(root->left, maxVal);
        result += DFS(root->right, maxVal);

        return result;
    }
public:
    int goodNodes(TreeNode* root) {
        return DFS(root, root->val);
    }
};
