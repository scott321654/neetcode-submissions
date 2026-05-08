class Solution {
    int dfs(TreeNode* root, int& result)
    {
        if (root == NULL)
        {
            return 0;
        }
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result = max(result, left + right);

        return 1 + max(right, left);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
        {
            return 0;
        }
        int result = 0;
        dfs(root, result);
        return result ;
    }
};