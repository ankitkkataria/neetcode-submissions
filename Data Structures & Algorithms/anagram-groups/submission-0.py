class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        sortedStringsMap = {}

        for string in strs:
            temp = ''.join(sorted(string))   # FIX 1: actually create sorted key

            listOfStrings = sortedStringsMap.get(temp, [])
            listOfStrings.append(string)     # FIX 2: append correctly
            sortedStringsMap[temp] = listOfStrings  # FIX 3: store list, not append result

        resultingList = []
        for k, v in sortedStringsMap.items():
            resultingList.append(v)

        return resultingList