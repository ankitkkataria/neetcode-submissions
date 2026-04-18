class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minToLeft = prices[0]
        maxProfit = 0
        for i in range(0, len(prices)):
            maxProfit = max(prices[i] - minToLeft, maxProfit)
            minToLeft = min(minToLeft, prices[i])
        return maxProfit
        
            

        