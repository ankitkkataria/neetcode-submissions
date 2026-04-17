class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>currMaxWindow(nums.size(), 0);
        currMaxWindow[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++) {
            // Check if you should start the new window here or continue to previous window.
            currMaxWindow[i] = max(currMaxWindow[i-1] + nums[i], nums[i]);
        }
        return *std::max_element(currMaxWindow.begin(), currMaxWindow.end());
    }
};
