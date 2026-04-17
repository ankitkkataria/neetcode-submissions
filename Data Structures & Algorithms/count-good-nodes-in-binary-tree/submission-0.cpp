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
    void dfs(TreeNode* root, int tempMax, int &res) {
        if(!root) return;
        // cout << "currently on "  << root->val << endl;
        if(root->val >= tempMax) {
            res++;
            tempMax = root->val;
            // cout << "counting the node " << root->val << " as a good node " << endl;
        }
        
        dfs(root->left, tempMax, res);
        dfs(root->right, tempMax, res);
    }

    int goodNodes(TreeNode* root) {
        int tempMax = -1e9;
        int res = 0;
        dfs(root, tempMax, res);
        return res;
    }
};
