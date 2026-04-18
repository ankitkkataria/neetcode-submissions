import heapq
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = []
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1;
        minHeap = []
        for key, value in freq.items():
            heapq.heappush(minHeap, (-1 * value, key))
        i = 0
        while i < k:
            value, key = heapq.heappop(minHeap)
            res.append(key)
            i += 1
        return res