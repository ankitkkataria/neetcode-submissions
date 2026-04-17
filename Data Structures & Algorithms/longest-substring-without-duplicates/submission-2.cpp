
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int res = 0;
        unordered_map<char, int>hashmap;
        while(j < s.size()) {
              hashmap[s[j]]++;
              if(hashmap.size() == j - i + 1) {
                res = max(res, j - i + 1);
              } else {
                // There is a repeating character in the current window
                while(hashmap.size() != j - i + 1) {
                      hashmap[s[i]]--;
                      if(hashmap[s[i]] == 0) {
                        hashmap.erase(s[i]);
                      }
                      i++;
                }
              }
              j++;
        }
        return res;
    }
};
