
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
    bool flag = 1;
    int DFS(TreeNode* root) {
        if(!root) return 0;
        int left = DFS(root->left);
        int right = DFS(root->right);
        if (left > right +1 || right > left + 1) {
            flag = false;
        }
        return 1 + max(left, right);    
    }
public:
    bool isBalanced(TreeNode* root) {
        DFS(root);
        
        return flag;
    }
};

