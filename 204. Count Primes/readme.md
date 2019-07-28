这又是关于数学的问题。。。

鉴于我一直在数学题上比较弱，我今天决定把王道论坛里面的数学章节都过一遍。。。。。

这个题我是看了王道，然后写的

第一次提交的代码 ，超时间了。。。。

```
from math import sqrt
class Solution(object):
    
    def func(self,num):
        
        num_sqrt = sqrt(num)
        
        i = 2
        
        while i <= num_sqrt:
            
            if num % i == 0:
                return False
            i +=1
        return True
        
    
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        for i in range(2,n):
            if self.func(i):
                count +=1
        return count
input:
999983
```

我的代码的时间复杂度是 O(n * n * sqrt(n))

999983 * sqrt(999983) = 9.9亿了  时间复杂度是有点高

我看了一下合数的定义， 
1.  所有4，6，8结尾的都是合数
2. 所有合数都可以写成质数的乘积

这就可以大大增加代码的速度了

基于上面的思想2 ，代码是ac了但是 只beat 5%
```
from math import sqrt
class Solution(object):
    
    def func(self,num):
        
        num_sqrt = sqrt(num)
        
        for item in self.data_store:
            
            if item > num_sqrt:
                break
            if num % item == 0:
                return False
        return True
        
    
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        count = 0
        
        self.data_store = []       
        
        for i in range(2,n):
            if self.func(i):
                count +=1
                self.data_store.append(i)
        return count
```
加了一个 [4,6,8] 也没啥用，速度提升不大，我智能做到这样了，我只能做到这个成都了，看看discussion里是怎么做的


网上看了一个代码，速度比我快20倍，代码也不是很好看懂，如下：

```
class Solution:
# @param {integer} n
# @return {integer}
    def countPrimes(self, n):
        if n < 3:
            return 0
        primes = [True] * n
        primes[0] = primes[1] = False
        for i in range(2, int(n ** 0.5) + 1):
            if primes[i]:
                primes[i * i: n: i] = [False] * len(primes[i * i: n: i])
        return sum(primes)
```

其实这个代码的思想来自于所有的合数都是由质数因子构成的 时间复杂度是O(sqrt(n) * n)

我的代码的时间复杂度是 粗略算是O(n * n * sqrt(n))

这个题，我的思路是完全被王道书带走了，王道里判断一个数是不是素数，给了一个sqrt的算法， 我觉得很快了，结果提交之后超时，我又改进了算法，ac了，然后我就不知道怎么提高了。 其实是有可提高的空间，思路如下：

给一个数是100，我们算99的时候 要遍历sqrt(99)来判断99是不是素数，算100的时候，又要算sqrt(100)来判断是不是素数，而这两次遍历的很多值都是重复遍历的，而这种重复性的东西就是我们提高效率的空间。

而这个作者就很好地解决了这个问题

如果我没看到这个解法，沿着当前思路继续思考地话。。。。

我们在遍历sqrt(99)的时候，因为都是跟99求余的，跟100也没有关系，这样的会陷入一个困境，貌似在遍历sqrt(99)的过程对计算100并没有什么帮助 。 这个是求素数的特点决定的，我们计算素数最快的方式就是sqrt(n)的时间复杂度，但是我们反过来思考，我们来算合数的时候是可以用O(1)的时间的，只要把任意两个数相乘就是合数了。 但是我们真的要用任意两个数相乘吗？ 那样的话时间复杂度是O(n * sqrt(n)) 其实这个复杂度就可以了，但是我们知道任意一个合数都是由质数因子构成的，所以我们可以进一步加快效率，只在碰到质数的时候再乘就可以了。 以上就是 思路的解析

easy题里面的解体思想其实很重要，应该花大精力去学习











