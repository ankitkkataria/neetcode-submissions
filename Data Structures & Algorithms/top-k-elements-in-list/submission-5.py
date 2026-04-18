import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1;
        minHeap = []
        for key, value in freq.items():
            heapq.heappush(minHeap, (value, key))
            if len(minHeap) > k:
                heapq.heappop(minHeap)

        while(len(minHeap)):
                value, key = heapq.heappop(minHeap)
                res.append(key)
            
        return res