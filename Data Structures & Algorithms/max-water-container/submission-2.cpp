class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i = 0;
        int j = nums.size()-1;
        int res = 0;
        while(i < j) {
            int minAmongBoth = min(nums[i], nums[j]);
            res = max(res, minAmongBoth * (j - i));
            if(nums[i] >= nums[j])
                j--;
            else 
                i++;
        }
        return res;
    }
};
