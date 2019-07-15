这个题型很新啊，找规律。。

最简单的方法是用暴力法，时间复杂度是O(n**2)

那我们就思考一下能不能用O(N)的时间复杂度做出来

想了一会之后，我想我找到规律了，灵感来自己于之前做的一道题是 最大连续值， 我的思路是找到一个积累量为非负的第一个索引，如果当前积累量是负，那就继续往下找，如果一直到数组最后一个值，积累量都是0 那就返回-1 

上面的思考是错误的
```
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
```
上面的例子正确答案是3 如果3的 回不到开始索引呢？ 怎么办，那就移动到索引4重新开始搜寻吗？ 很显然不行，那样时间复杂度又是O(n**2)

上面的思考又是错的，如果数据改为如下：

```
gas  = [1,2,3,4,5]
cost = [3,4,6,1,2]
```
我们在第二次循环的时候走到索引2积累量为-1 ，那我们根本就不需要考虑从ix 等于4开始的情况，因为ix等于3的地方积累量大于零，尚且都都不能回到3，减少一个非负积累量能让他回到4吗？ 不可能的。  基于以上想法，开始写程序，我将写的程序时间复杂度是O(n)


代码两次提交ac了，但是只beat掉 25.76%的代码，不会吧，大家的算法比O(n)还快吗？ 

我去看下discussion

看了一下discussion里面的解决方案，我的时间复杂度是O(2n)，而他的时间复杂度是O(n)

```
class Solution:
    def canCompleteCircuit(self, gas, cost):
        m = s = 0
        s_min = gas[0]
        for i in range(len(gas)):
            s += gas[i] - cost[i]
            if s < s_min:
                s_min = s
                m = i
        return (m + 1) % len(gas) if s >= 0 else -1

```
这个代码看不懂啊，什么意思啊？

我又看到另一个方案

```
class Solution(object):
    def canCompleteCircuit(self, gas, cost):
        """
        :type gas: List[int]
        :type cost: List[int]
        :rtype: int
        """
        if sum(gas) < sum(cost):
            return -1
        index = 0
        current = 0
        for i in range(len(gas)):
            current += gas[i]-cost[i]
            if current < 0:
                current = 0
                index = i+1
        return index
```
 
这个老哥代码跟我的很像，但是他用了sum(gas) < sum(cost) ，理解问题比我深刻，这个是正确的合理的思路












