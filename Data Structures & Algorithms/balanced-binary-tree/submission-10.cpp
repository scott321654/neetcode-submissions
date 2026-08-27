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
public:
    bool flag = true;
    
    int DFS(TreeNode* root) {
        if (root==nullptr) return 0;
        int left_layer = DFS(root->left);
        int right_layer = DFS(root->right);
        if (abs(left_layer - right_layer) > 1) {
            flag = false;
        }
        return 1 + max(left_layer, right_layer);
    }

    bool isBalanced(TreeNode* root) {
        DFS(root);

        return flag;
    }
};

