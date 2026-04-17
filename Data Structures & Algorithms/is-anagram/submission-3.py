from collections import Counter
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # When sorted two anagrams become the same string
        # if len(s) != len(t):
        #     return False
        return sorted(s) == sorted(t)

        
        