代码也是一次ac

```
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        count = 0
        
        while n:
            if n & 1:
                count +=1
            n = n /2
        return count
```

这个代码在debug的时候遇到一个问题，下面的代码会无限循环

```
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        count = 0
        
        while n:
            if n & 1:
                count +=1
            n >> 1
        return count
```

上面代码我傻逼了， 应该改成 n = n >> 1

有一个更快的代码：

```
class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        count = 0
        
        while n:
            count +=1
            
            n = n & (n-1)
        return count
```


