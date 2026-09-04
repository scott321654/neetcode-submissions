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
    int idx = 0;
    unordered_map<int, int> mapss;
    TreeNode* build(vector<int>&preorder, int l, int r) {
        if (l > r) return nullptr;

        
        int root_val = preorder[idx++];
        int inorder_mid = mapss[root_val];
        TreeNode* node = new TreeNode(root_val);

        node->left = build(preorder, l,  inorder_mid- 1);
        node->right = build(preorder, inorder_mid + 1, r);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            for (int i = 0; i < inorder.size(); i++) {
                mapss[inorder[i]] = i;
            }

            return build(preorder, 0, inorder.size() - 1);
    }       
};
