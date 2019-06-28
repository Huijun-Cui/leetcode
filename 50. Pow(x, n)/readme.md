这个题目做起来，思路还挺清晰，算法也应该是最优的 beat 98.18%
```
class Solution:
    def myPow(self, x: float, n: int) -> float:
        num_store = 1
        
        if x == 0:
            return 0
        if n == 0:
            return 1
        elif n < 0:
            n = -n
            x = 1/x
        _x = x
        mi = 1
        
        while n > 0:
            while mi *2 <= n:
                _x = _x * _x

                mi *= 2
            n = n -mi
            mi = 1
            num_store *= _x
            _x = x
        
        return num_store


```