class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int start = 0;
        int end = nums.size() - 1;
        while(start <= end) {
            int mid = start + (end - start)/2;
            int nextToMid = (mid + 1) % n;
            int prevToMid = (mid - 1 + n) % n;
            if(nums[mid] <= nums[prevToMid] && nums[mid] <= nums[nextToMid]) 
                return nums[mid];
            else if(nums[mid] > nums[end]) 
                start = mid + 1;
            else 
                end = mid - 1;
            
        }

    }
};
