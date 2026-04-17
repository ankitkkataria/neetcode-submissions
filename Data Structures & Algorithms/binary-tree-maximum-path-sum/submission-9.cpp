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
    int dfs(TreeNode* root, int &res) {
        if(!root) return 0;
        int left = dfs(root->left, res);
        if(left < 0) left = 0;
        int right = dfs(root->right, res);
        if(right < 0) right = 0;
        res = max(root->val + left + right, res);
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};

