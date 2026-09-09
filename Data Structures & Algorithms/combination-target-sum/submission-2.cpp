class Solution {
public:

    void dfs(int idx, vector<int>&nums, int target, int currSum, vector<int>&temp ,vector<vector<int>>&res) {

        // Base condition
        if(currSum >= target || idx == nums.size()) {
            if(currSum == target)
                res.push_back(temp);
            return;
        }

        // Pick
        temp.push_back(nums[idx]);
        dfs(idx, nums, target, currSum + nums[idx], temp, res);
        temp.pop_back();
        // Not pick
        dfs(idx + 1, nums, target, currSum, temp, res);

    }



    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int currSum = 0;
        vector<int>temp;
        dfs(0, nums, target, currSum, temp, res);
        return res;
    }
};
