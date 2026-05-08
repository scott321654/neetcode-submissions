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
    int goodNodes(TreeNode* root) 
    {
        if (root == nullptr) return 0;

        // Stack to hold pairs of nodes and the maximum value encountered along the path
        std::stack<std::pair<TreeNode*, int>> stack;
        stack.push({root, root->val});
        int goodNodesCount = 0;

        while (!stack.empty()) 
        {
            auto [node, maxVal] = stack.top();
            stack.pop();

            if (node->val >= maxVal) 
            {
                goodNodesCount++;
            }

            maxVal = std::max(maxVal, node->val);

            // Push the left and right children to the stack with updated maxVal
            if (node->right != nullptr) 
            {
                stack.push({node->right, maxVal});
            }
            if (node->left != nullptr) 
            {
                stack.push({node->left, maxVal});
            }
        }

        return goodNodesCount;
    }
};
