class Solution {
public:

    void f(int i, vector<int>&nums,vector<int>&temp,vector<vector<int>>&res) {
        // Base case
        if(i == nums.size()) {
           res.push_back(temp);
           return;
        }

        // Pick the element
        temp.push_back(nums[i]);
        f(i + 1, nums, temp, res);

        // Not pick the element
        temp.pop_back();
        f(i + 1, nums, temp, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;      
        vector<int>temp;
        f(0, nums, temp, res);
        return res;
    }
};

