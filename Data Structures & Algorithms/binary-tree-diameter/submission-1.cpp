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

    int f(TreeNode* root, int &res) {
        if(!root) return 0;
        
        // Preorder traversal
        int leftHeight = f(root->left, res);
        int rightHeight = f(root->right, res);

        // I will have to heights of both the left and right paths from this TreeNode
        res = max(res, 1 + leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        f(root, res);
        return res - 1;
    }
};

