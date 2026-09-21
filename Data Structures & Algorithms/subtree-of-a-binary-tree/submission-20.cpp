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
    bool isSameTree(TreeNode *q, TreeNode* p) {
        if (q == nullptr && p == nullptr)
            return true;
        else if (q == nullptr || p == nullptr) 
            return false;
        else {
            if (q->val != p->val)
                return false;
        }

        return isSameTree(q->left, p->left) && 
            isSameTree(q->right, p->right); 
    } 

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) return false;
        if (isSameTree(root, subRoot)) return true;

        return isSubtree(root->right, subRoot) || isSubtree(root->left, subRoot);
    }
};
