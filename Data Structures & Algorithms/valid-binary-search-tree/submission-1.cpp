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
private:
    bool valid(TreeNode* root, long left, long right)
    {
        if (root == NULL)
        {
            return true;
        }
        if (!(left < root->val && root->val < right))
        {
            return false;
        }

        return (valid(root->right, root->val, right) && valid(root->left, left, root->val));
    }
public:
    bool isValidBST(TreeNode* root) 
    {
        return valid(root, LONG_MIN, LONG_MAX);
    }
};
