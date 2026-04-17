class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool>hashmap;
        for(auto num : nums) {
            if(hashmap[num]) return true;
            hashmap[num] = true;
        }
        return false;
    }
};