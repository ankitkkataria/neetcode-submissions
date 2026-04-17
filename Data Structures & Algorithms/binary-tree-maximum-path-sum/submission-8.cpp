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
        if(root == NULL) 
            return 0;

        // Give me the amx sum path to the left and the right of this node.
        int leftMax = dfs(root->left,res);
        if(leftMax < 0) 
            leftMax = 0;
        int rightMax = dfs(root->right, res);
        if(rightMax < 0)
            rightMax = 0;
        // At each node compute the sum you could get if this current node was the root of the path.
        res = max(res, leftMax + rightMax + root->val);

        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};
