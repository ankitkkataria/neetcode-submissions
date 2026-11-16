class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefixSumCount;
        prefixSumCount[0] = 1;
        int prefixSum = 0;
        int res = 0;
        for(auto num : nums) {
            prefixSum += num;
            if(prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
                res += prefixSumCount[prefixSum - k];   
            }
            prefixSumCount[prefixSum]++;
        }
        return res;
    }
};