这个题的肯定是O(n)的时间复杂度了，关键是one-pass 还是two-pass

我的初步思路是 先遍历找更小的点，然后遍历寻找更大的点，如果在寻找更大的点时候遇到了更小的点，那就更新利润，直到结束。

切记啊，代码要想清楚再写  ,beat 99.73%
```
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = 888888888888888888
        max_profit = 0
        for i,item in enumerate(prices):
            if item - min_price > max_profit:
                max_profit = item - min_price
            if item < min_price:
                min_price = item
        if max_profit < 0:
            return 0
        else:
            return max_profit
```

网上看了一个代码构思也很巧妙，把他变成一个动态规划的问题，问题分解方式是 上一时刻的赚钱最大的值基础上，加上这一时刻的盈利，同时这一时刻的盈利小于零的话这个时刻的盈利应该置为零

