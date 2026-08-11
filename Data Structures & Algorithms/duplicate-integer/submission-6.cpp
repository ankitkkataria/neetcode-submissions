class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int>hashmap;
        for(int num : nums) {
            if(hashmap.find(num) != hashmap.end())
                return true;
            hashmap[num]++;
        }
        return false;
    }
};