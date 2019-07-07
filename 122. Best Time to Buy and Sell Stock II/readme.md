这个题我的理解就是不断地再最低点买，最高点卖

这种easy 题我觉得就应该是一次ac 但是总是出错，逻辑不够请详细啊。。。
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        min_price = prices[0]
        max_profit = 0
        sum_profit = 0
        buy_price = 0
        
        for i,item in enumerate(prices):
            if i ==0:
                continue
            if i > 0 and prices[i] - prices[i-1] < 0:
                sum_profit += max_profit
                max_profit = 0
                min_price = prices[i]
            
            else:
                max_profit = prices[i] - min_price
        if max_profit:
            sum_profit += max_profit
        return sum_profit
```
看了一下网上地代码，那写地真地叫漂亮

```
class Solution(object):
    def maxProfit(self, prices):
        return sum([
            max(prices[i] - prices[i - 1], 0) for i in xrange(1, len(prices))])
```
这种变成思想真地应该锻炼