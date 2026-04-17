class Solution
{
public:
    void f(int idx, vector<int> &nums, vector<vector<int>> &res, vector<int> &temp)
    {
        if (idx == nums.size())
        {
            res.push_back(temp);
            return;
        }

        // Pick 
        temp.push_back(nums[idx]);
        f(idx + 1, nums, res, temp);

        // Not Pick
        temp.pop_back();
        f(idx + 1, nums, res, temp);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> temp;
        f(0, nums, res, temp);
        return res;
    }
};
