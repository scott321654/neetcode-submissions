class Solution {
    int DFS(TreeNode* node, bool& result)
    {
        if (node == NULL)
        {
            return 0;
        }

        int left = DFS(node->left, result);
        int right = DFS(node->right, result);
        if (abs(left - right) > 1)
        {
            result = false;
        }

        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }

        bool result = true;
        DFS(root, result);

        return result;
    }
};
