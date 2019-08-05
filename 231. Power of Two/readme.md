代码是下面这样，三次ac

```
class Solution:
    def isPowerOfTwo(self, n: int) -> bool:
        
        
        
        num = 2
        
        while True:  
            if n ==0:
                return False
            if n == 1:
                return True
            if num == n:
                return True
            
            if num * num <= n:
                num = num*num
            else:
                if n % num != 0:
                    return False
                n = n //num
                
                num = 2
                
```

看以下答案是怎么写的吧