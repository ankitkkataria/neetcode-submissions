class Solution:
    def characterReplacement(self, s: str, k: int) -> int:

        def substringValid(freqMap, k):
            sumOfAllFreq = 0
            maxFreq = 0
            for key, value in freqMap.items():
                maxFreq = max(maxFreq, value)
                sumOfAllFreq += value
            return (sumOfAllFreq - maxFreq) <= k
             

        i, j = 0, 0
        freqMap = {}

        res = 0
        while j < len(s):
            freqMap[s[j]] = freqMap.get(s[j], 0) + 1
            if(substringValid(freqMap, k)):
                res = max(res, j - i + 1)
            else: 
                while(i < len(s) and not substringValid(freqMap, k)):
                    freqMap[s[i]] -= 1
                    i += 1
            j += 1
        return res