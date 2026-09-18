



class Solution {
    void swapTree(TreeNode **left, TreeNode **right) {
        TreeNode* tmp = *left;
        *left =  *right;
        *right = tmp;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) 
            return root;
            
        swapTree(&root->left, &root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
