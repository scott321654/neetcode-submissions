class Solution {
    int DFS(TreeNode* root, int result)
    {
        if (root == NULL)
        {
            return 0;
        }
        
        int left = DFS(root->left, result);
        int right = DFS(root->right, result);
        result = max(left + right, result);
        return 1 + max(left, right);
    }
public:
    int maxDepth(TreeNode* root) {
        int result = 0;
       return DFS(root, result);
    }
};
