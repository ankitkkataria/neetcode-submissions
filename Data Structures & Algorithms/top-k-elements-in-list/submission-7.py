import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # count of each num in nums
        count = {} 
       
        freq = [[] for i in range(len(nums) + 1)]
        for num in nums:
            count[num] = 1 + count.get(num, 0)

        for num, numCount in count.items():
            freq[numCount].append(num)

        # result list 
        res = []
        for i in range(len(freq)-1, 0, -1):
            for num in freq[i]:
               res.append(num)
               if len(res) == k:
                   return res 
        