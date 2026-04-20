class Solution:
  

    def minWindow(self, s: str, t: str) -> str:

        def compareCover(sWindowMap, tMap):
            for k,v in tMap.items():
                if tMap.get(k) > sWindowMap.get(k, 0):
                    return False
            return True
        
        i, j = 0, 0
        res = len(s) + 1
        finalString = ''
        sWindowMap, tMap = {}, {}

        for c in t:
            tMap[c] = 1 + tMap.get(c, 0)

        while(j < len(s)):
            sWindowMap[s[j]] = 1 + sWindowMap.get(s[j], 0)
            j += 1
            while(i < len(s) and compareCover(sWindowMap, tMap)):
                if(res > j - i ):
                    res = j - i 
                    finalString = s[i: j]
                sWindowMap[s[i]] -= 1
                i += 1
            
        return finalString
                


            
                
            


        

        