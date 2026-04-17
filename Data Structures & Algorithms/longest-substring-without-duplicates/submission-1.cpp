class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int res = 0;
      int i = 0;
      int j = 0;
      unordered_map<char,int>hashmap;
      while(j < s.size()) {
        // Add the element to the hashmap
        hashmap[s[j]]++;
        if(hashmap.size() == j - i + 1) {
            res = max(res, j - i + 1);
        }
        else {
           // In my current window there is a repeating character
           while(hashmap.size() != j - i + 1)  {
             // Remove character from the begining of the string (which is pointed by i)
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
