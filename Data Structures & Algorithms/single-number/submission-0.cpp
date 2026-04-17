class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorOfAllElements = 0;
        for(int num : nums) {
            xorOfAllElements ^= num;
        }
        return xorOfAllElements;
    }
};
