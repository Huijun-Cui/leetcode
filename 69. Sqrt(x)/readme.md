这个题目 我想到的数学规律是 x= x* x 这样的形式，提交了下面的方案，结果 超时了

```
class Solution:
    def mySqrt(self, x: int) -> int:
        if x== 0:
            return 0
        elif x <= 3:
            return 1
        
        i = 2
        while True:
            if i ** 2 > x and (i-1)**2 <=x:
                return i-1
            if (i*i)**2 < x:
                i = i* i
            else:
                i +=1
        return i-1
```

要想一想别的办法

这个问题，我最后还是没想出来， 我当时是要想一想别的办法，但是还是又回过头去纠结 x= x* x这种数学规律了，看了以下答案，看到他们是用binary search做的，我才恍然大悟， shit ,我当时为什么没想出来

用binary search的话，这个题是一个 n*log(n)的时间复杂度，但是我之前尝试的算法，说实话，时间复杂度是多少是算不出来的（很难算）,   这种 x = x * x 这种数规律 是之前是在 50.Pow(x,n)里见到的 ，还有之前王道考研里面快速求 a 的b 次幂里面也谈到了这点 。 在这种例子里面也是可以算出时间复杂度的,是log(n) ，通过这个题，我发现一个现象，就是不能准确估算出时间复杂度的算法，不要去多想

我知道了要用binary search去做之后，但是仍然遇到了麻烦， 让我很难受，如下：

```
class Solution:
    def mySqrt(self, x: int) -> int:
        def _sqrt(low,high,n):
            mid = None
            while low < high:
                mid = (low + high) //2
                if mid ** 2 == n:
                    return mid
                if mid ** 2 < n:
                    low = mid+1
                else:
                    high = mid -1
            if low ** 2 == n:
                return low
            if low ** 2 > n:
                
                
            return low
        if x <= 1:
            return x
        return _sqrt(1,x,x)
```

这个代码写的是不对的，最终坐标会落在 low 或者mid上，但是这个时候我没办法确定应该用哪个值，确定要用哪个值首先要确定以下几点， 
low\*\*2 和 n 谁大？ mid\*\*2 和 n 谁大？
如果low\*\*2 > n  and mid \*\*2 <n 那就是返回 mid
如果 low\*\*2 <n and mid \*\* >n 那就是返回 low
以上这些都好判断，但是如果出现如下情况，怎么处理？
low\*\*2 < n and mid \*\*2 < n 
low\*\*2 > n and mid \*\*2 > n

对这两种情况，我想给出证明，不会出现这种情况，但是没有相出来，我决定直接提交，看看错误样例是什么情况。。。

```
Input : 5
Output : null
Expected 2 
class Solution:
    def mySqrt(self, x: int) -> int:
        def _sqrt(low,high,n):
            mid = None
            while low < high:
                mid = (low + high) //2
                if mid ** 2 == n:
                    return mid
                if mid ** 2 < n:
                    low = mid+1
                else:
                    high = mid -1
            if low ** 2 == n:
                return low
            if low ** 2 > n and mid**2 < n:
                return mid
            if low**2 < n and mid**2 > n:
                return low
            else:
                
        if x <= 1:
            return x
        return _sqrt(1,x,x)
```
代码就是这个样子 我再看看别人写的代码，就可以避免我这个问题

```
class Solution(object):
    def mySqrt(self, x):
        left, right = 0, x + 1
        while right - left > 1:
            mid = (left + right) >> 1
            if mid ** 2 <= x:
                left = mid
            else:
                right = mid 
        return left

```
寥寥几行代码，但是非常跟这个题目贴切，这个程序的功能是使得left\*\*2 <= x , 而right > x,而且这个程序的\
终止条件是while right-left > 1  这样程序结束后left 和 right是相邻的。


另外一个代码
```
class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        def bSearch(x):
            i = 0
            j = x
            while i < j:
                mid = (i+j) / 2
                res = mid ** 2
                nex = (mid+1) ** 2
                if res == x:
                    return mid
                elif nex == x:
                    return mid+1
                elif res < x < nex:
                    return mid
                elif x < res:
                    j = mid-1
                else:
                    i = mid+1
            return i
        if x == 1:
            return 1
        return bSearch(x)
```

这个代码很繁琐，很显然这位老哥也遇到了我遇到的问题，所以他在循环体内部连续用了 if elif elif elif else 这样的判断\
语句 。  
首先这个代码的问题在 while i < j 上，如果是在精确查找的问题上这么写是没问题的，但是我们这个问题他应该说是一个范围查找（这么定义不准确，我也不知道怎么用其他方式定义），就是要查找这么一个元素，他的平方比target number小，但是他的下一个元素比target 元素大。  但是在这个代码上 while i < j 最终停留在 i==j 上，程序不能确定 i-1 和 i + 1的情况就像我自己在我的程序中讨论的那样。  所所以这个老哥加了这么多if else 是因为他意识到这个问题，同时他还发现我们的mid 肯定指向过 result number, 所以他加了一个 res < x < next 这样的条件。

写到这里我自己有一个感觉，重新考虑一下我的程序，我觉得最终的结果一定出现在 i,i-1,i+1 这三个位置，我自己再提交以下的程序再验证一下 

```
class Solution:
    def mySqrt(self, x: int) -> int:
        def _sqrt(low,high,n):
            mid = None
            while low < high:
                mid = (low + high) //2
                if mid ** 2 == n:
                    return mid
                if mid ** 2 < n:
                    low = mid+1
                else:
                    high = mid -1
            if low**2 == n:
                return low
            elif low ** 2 < n:
                return low
            else:
                return low-1
                
        if x <= 1:
            return x
        return _sqrt(1,x,x)
```

事实证明我的想法是对的 这个代码也已经ac了


