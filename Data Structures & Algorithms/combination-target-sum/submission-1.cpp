class Solution
{
public:
    void f(int idx, vector<int> &nums, int target, int tempSum, vector<int> &temp, vector<vector<int>> &res)
    {
        
        if(idx >= nums.size() || tempSum >= target) {
            if(tempSum == target)
            res.push_back(temp);
            return;
        }

        // Pick 
        temp.push_back(nums[idx]);
        f(idx, nums, target, tempSum + nums[idx], temp, res);

        // Not Pick
        temp.pop_back();
        f(idx + 1, nums, target, tempSum, temp, res);
    }

    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        // Find unique combinations that sum upto the target
        vector<int> temp;
        vector<vector<int>> res;
        int tempSum;
        f(0, nums, target, tempSum, temp, res);
        return res;
    }
};
