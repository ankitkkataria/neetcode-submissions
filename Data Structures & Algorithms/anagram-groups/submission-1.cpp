class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> hashmap;
        for(auto str : strs) {
            string strCpy = str;
            sort(str.begin(), str.end());
            hashmap[str].push_back(strCpy);
        }
        vector<vector<string>> res;
        for(auto entry : hashmap){
            vector<string>resEntry;
            for(auto num : entry.second) {
                resEntry.push_back(num);
            }
            res.push_back(resEntry);
        }
        return res;
    }
};
