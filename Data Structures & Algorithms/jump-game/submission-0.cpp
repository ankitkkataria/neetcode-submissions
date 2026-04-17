class Solution {
public:
    bool canJump(vector<int>& nums) {
       int targetIndex = nums.size()-1;
       for(int i = nums.size()-2 ; i >= 0 ; i--){
            if(i + nums[i] >= targetIndex) {
                targetIndex = i;
            }
       }
       return (targetIndex == 0);
    }
};
