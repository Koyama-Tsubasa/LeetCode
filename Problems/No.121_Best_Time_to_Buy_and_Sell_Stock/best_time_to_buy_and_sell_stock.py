class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        
        # parameters
        max_profit = 0
        buy_price = prices[0]
        
        # start compute
        for price in prices:
            buy_price = min(buy_price, price)
            max_profit = max(max_profit, price-buy_price)
        
        return max_profit
