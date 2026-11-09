class Solution(object):
    def maxProfit(self, prices):
        bestBuy = float('inf')
        maxProfit = 0

        for price in prices:
            bestBuy = min(bestBuy, price)
            maxProfit = max(maxProfit, price - bestBuy)
        return maxProfit
        