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
    
void tree_swap(TreeNode** p, TreeNode** q) {
    TreeNode* tmp = *p;
    *p = *q;
    *q = tmp;
}

public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        tree_swap(&root->left, &root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
