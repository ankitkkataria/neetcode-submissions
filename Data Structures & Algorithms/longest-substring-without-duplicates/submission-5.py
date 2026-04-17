from collections import defaultdict
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        i = 0;
        j = 0;
        hashmap = defaultdict(int)
        res = 0
        while(j < len(s)):
            hashmap[s[j]] += 1
            if(len(hashmap) == j - i + 1):
                res = max(res, j - i + 1)
            else:
                while(i < len(s) and len(hashmap) != j - i + 1):
                    hashmap[s[i]] -= 1
                    if(hashmap[s[i]] == 0):
                        del hashmap[s[i]]
                    i += 1
            j += 1
        
        return res
        


            
        