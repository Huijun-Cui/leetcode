这个问题 我知道，是一个动态规划问题,代码也是一次就过了,beat 88.14%

```
class Solution:
    def climbStairs(self, n: int) -> int:
        if n <=2:
            return n
        num1 = 1
        num2 = 2
        
        for i in range(3,n+1):
            num1,num2 = num2,num1+num2
        return num2
```