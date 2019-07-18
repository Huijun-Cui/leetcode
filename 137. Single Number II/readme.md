这个题看着，完全没思路啊，这个题我在剑指offer里是见过的，但是现在想不起来了。。。。

想了好久终于想到了方案，几乎是在要放弃的时候。。。。 完全没有借助剑指offer里的思想


上面的思想是错误的，我写出了下面这个错误的代码

```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        num = 0
        
        for item in nums:
            num ^= item
        
        for item in nums:
            num ^= item
        
        return num
```


这个问题我想不出来了,看答案吧，明天再看，好困。。。add  

看了答案之后，我知道了这个就是按位置相加，然后对3取模，然后再把二进制数变成整数输出出来，但是我在实际写的时候遇到了如下的问题
```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        
        num_store = [0] * 32
        
        for i in range(32):
            for item in nums:
                tmp = (item>>i) & 1
                num_store[i] += tmp
        
        i = 0
        
        ret_num = 0
        while i<len(nums)-1:
            num_store[i] = num_store[i] % 3
            ret_num += (2 ** i) *  num_store[i]
            i+=1
        if nums[-1] == 1:
            return -ret_num
        return ret_num


Your input
[-2,-2,1,1,-3,1,-3,-3,-4,-2]
Output
508
Expected
-4
```

原因是负数在内存中是以补码的形式存在的，我们最后还要加上补码转换到整数的过程。按位置取反然后再加1，感觉时间复杂度就高了啊。 

我还要再次看看 discussion里面是怎么做的

```
class Solution:
# @param A, a list of integer
# @return an integer
def singleNumber(self, A):
    ans = 0
    for i in xrange(0,32):
        count = 0
        for a in A:
            if ((a >> i) & 1):
                count+=1
        ans |= ((count%3) << i)
    return self.convert(ans)
    
def convert(self,x):
    if x >= 2**31:
        x -= 2**32
    return x
```
这个函数里面有一个地方就是补码到原码的转换，就是 convert(x)

这个变换我看得不是很明白，我觉得我需要把补码，原码复习一下  太困了，在调生物钟，根本看不进去内容，希望今天能按时入睡，shit!!!


## 原码 补码

#### 机器数

一个数在计算机中的二进制表示就是机器数

比如:
+3的机器数是 00000011 .
-3的机器数是 10000011 .

#### 真值

带符号位的机器数对应的真值称为机器数的真值

00000011 的真值是 +3   这里可以看出 正数的机器数等于真值

10000011 的真值是 -3

#### 原码

原码就是 符号位加真值的二进制数

### 补码

定义略过吧。。。

#### 假如补码的意义

假如补码机制之后计算机可以指进行加法运算，并且把符号位也带入运算。

把这些概念过了之后，我还是不能从直观上理解
```
def convert(self,x):
    if x >= 2**31:
        x -= 2**32
    return x
```

这个代码，那我就背下来吧。  这个题的这种解法就到此为止，我现在再看看剑指offer里面是怎么做的


