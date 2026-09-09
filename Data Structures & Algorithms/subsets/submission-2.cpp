class Solution {
public:

    void dfs(int idx, vector<int>&nums, vector<vector<int>>&res, vector<int>&temp) {
        if(idx == nums.size()) {
            res.push_back(temp);
            return;
        }
        // Pick
        temp.push_back(nums[idx]);
        dfs(idx+1, nums, res, temp);
        temp.pop_back();
        dfs(idx+1, nums, res, temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>temp;
        dfs(0, nums, res, temp);
        return res;
    }
};
