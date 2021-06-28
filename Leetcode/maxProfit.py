class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxP = 0
        smallest = prices[0]
        nextP = 0
        for i in range(1,len(prices)):
            if maxP < (prices[i]-smallest):
                maxP = prices[i]-smallest
                
            if smallest > prices[i]:
                smallest = prices[i]
                
            
            
        return maxP
                
            
        