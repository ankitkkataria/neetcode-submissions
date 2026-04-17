class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int>hashmap1;
        unordered_map<char,int>hashmap2;
        for(auto c : s)
            hashmap1[c]++;
        for(auto c : t)
            hashmap2[c]++;
        return hashmap1 == hashmap2;
    }
};
