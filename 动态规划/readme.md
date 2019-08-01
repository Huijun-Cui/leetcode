## 这次主要来总结一下动态规划方面的问题，希望能总结出一个方法论，能够快速找到动态规划的方法

#### 青蛙跳

首先最先接触到动态规划是在青蛙跳的问题上

青蛙可能两条，也肯能一跳，问到第n个台阶有多少种跳法？ 

很显然
f(n) = f(n-1) + f(n-2)
...
f(3) = f(2) + f(1)

那我们用递归函数去做的话就是这样
```
int func(int n,gloval var):
    if n == 1:
        return 1
    if n == 2:
        return 2
    return func(n-1) + func(n-2)
```
以上代码的时间复杂度是多少呢？ 

是O(2**n) 如果用画出树形图，他是一个完全二叉树，n就是树的高度

而我们用动态规划去做的话，时间复杂度只有O(n)，方法就是自底向上考虑问题

剑指offer里面有介绍动态规划的特点，其实第一条就是说他有求解最优解的特点，但是可以发现，这个特点并不是一直存在的，在这个例子里面就不存在。 所以我不想用剑指offer里面的思想，而是自己总结一个。

我觉得动态规划，如果一时半会看不出规律那就尝试用暴力方法去

比如这个青蛙跳的问题， 如果我们看不出规律，那就要想想用暴力方法怎么去做。

暴力方法：

第一步有两种跳法，
跳一步，然后再完成剩下的 n-1步，剩下的n-1步第一步有两种跳法，如此循环
跳二步，然后再完成剩下的 n-2步，剩下的再如此循环。

这样我们就写出了递归函数

写完递归函数之后，我们要看看递归函数是不是动态规划解法？ 比如上面的青蛙跳程序就步是动态规划解法，时间复杂度很高，但是不是所有的递归函数都不是动态规划解法，我们再看个例子：

```
def func(n):
    if n == 0:
        return True
    return func(n-1)
```
上面这个程序时间复杂度是O(n)

如果把上面的程序改一下

```
def func(n):
    if n == 0:
        return True
    return func(n-1) and func(n-2) and func(n-3)
```

这个程序的时间复杂度是O(3**n)的时间复杂度

我们拿leetcode 里面的一道题来举例，来弄清一下递归函数的动态规划的特性

leetcode 39题

代码如下：

```
class Solution:
    def combinationSum(self, candidates, target):
        res = []
        candidates.sort()
        def dfs(nums, target, index, path, res):
            if target < 0:
                return  # backtracking
            if target == 0:
                res.append(path)
                return 
            for i in range(index, len(nums)):
                if nums[i] > target: break #improvement
                dfs(nums, target-nums[i], i, path+[nums[i]], res)
        dfs(candidates, target, 0, [], res)
        return res
```

这个代码的时间复杂度是多少呢？ 是（n**n），那这个题具备动态规划的特性吗？ 

我们来看  dfs(nums, target, index, path, res) 可以发现，这个函数在各次调用中都不会出现重复的情况，所以步具备动态规划特性。

再看看 leetcode 139 Word Break

这个题，是用动态规划做的，但是一时找不出动态规划的思路，怎么做？ 尝试用暴力法试试。我之前写的代码

```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        data = {}
        for item in wordDict:
            data[item] = 1
        def func(_s):
            flag = False
            if len(_s) == 0:
                return True
            i = len(_s)-1
            while i >=0:
                if _s[:i+1] in data:
                    
                    flag = flag or func(_s[i+1:])
                    if flag:
                        return True
                i -=1
            return flag
        return func(s)
```

这个代码是能得到正确答案的，但是时间复杂度是非常高的。 这个代码的时间复杂度是多少呢？ 不太好算，但是我们来看一下递归函数 func(_s) 在历次调用中会不会出现的重复的调用，很显然是会的。比如下面的例子
```
s = "aaaaaaab" 
wordDict = [a,aa,aaa,aaaa,aaaaa,aaaaa,b]
```
所以这个题是可以用动态规划来做的 。

以上是我们分析了暴力方法，递归函数，以及动态规划算法的关系，接下来我们来看下，怎么从递归方法推到出动态规划算法

#### 动态规划算法的推导

动态规划算法的思路就是从小子集推到大子集。就是leetcode里面的自底向上啦

我们动态规划的算法是让递归函数部分能够用O(1)的时间去解决


#### 动态规划方法论验证

接下来我们拿几个实例来验证一下上面的思想，上面的分析属于训练集，下面的例子属于验证集合，咱们来验证一下这种方法论的泛化性


leetcode 198 . House Robber

这个题其实很容易看出来，这是一个动态规划的问题，但是我自己写的动态规划和网上的动态规划不一样。是两种思想体系。 所以这个题我打算还是按照上面的方法论来做一下


Inout [1,2,4,1,8,5,3,2,1,3,6,7] 
暴力法：

第一步选择：
1.  抢第一个商店 那接下来要从 [4,1,8,5,3,2,1,3,6,7] 抢
2.  抢第二个商店 那接下来要从 [1,8,5,3,2,1,3,6,7] 抢

随意这个很显然写成递归函数的话是会有重复递归函数调用

```
def func(nums):
    if len(nums) == 2:
        return max(nums)
    return max(nums[0] + func(nums[2:]),func(nums[1:]))
```

接下来我们再来看看leetcode 10 正则匹配

首先递归函数剑指offer里面已经写好了，我们直接拿他的代码来分析





















