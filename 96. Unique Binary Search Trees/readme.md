这个题就是接着95题改就行了，因为只是输出个数 ，我把95题结果加了len ,然后超时了

代码如下：
```
class Solution:
    def numTrees(self, n: int) -> int:
        def func(nums):
            if len(nums) == 0:
                return [None]
            
            else:
                root_list = []
                for i,item in enumerate(nums):
                    left_node = func(nums[:i])
                    right_node = func(nums[i+1:])
                    for left_item in left_node:
                        for right_item in right_node:
                            tmp_root = TreeNode(item)
                            tmp_root.left = left_item
                            tmp_root.right = right_item
                            root_list.append(tmp_root)
                
                return root_list
        if n == 0:
            return len([])
        return len(func([item+1 for item in range(n)]))

Input: 19

```
刚开始报错之后，我第一个反应是 是不是把函数返回值从列表改成个数就可以了，如下
```
class Solution:
    def numTrees(self, n: int) -> int:
        def func(nums):
            if len(nums) == 0:
                return [None]
            
            else:
                root_list = []
                for i,item in enumerate(nums):
                    left_node = func(nums[:i])
                    right_node = func(nums[i+1:])
                    for left_item in left_node:
                        for right_item in right_node:
                            tmp_root = TreeNode(item)
                            tmp_root.left = left_item
                            tmp_root.right = right_item
                            root_list.append(tmp_root)
                
                return root_list
        if n == 0:
            return len([])
        return len(func([item+1 for item in range(n)]))
```
仍然是超时，只能说明我太naive了，这个明显是算法复杂度的问题，怎么能是解决一返回形式就能解决的问题呢? 我的这个算法\
时间复杂度是 O(n ** n)

这个算法想改进真的比较困难，因为我们之前做题都是观察，建模，但是这个题我去观察的话就是 生成一系列的结果，然后数个数啊。\
除非这个生成过程可以用动态规划去解决，但是好像动态规划也不行啊

在观察的过程中我发现一个现象，就是给定的一个序列，他们二叉树的组合方式个数，只跟他们序列长度有关系，比如： \
无论是 [0,1,2] 还是[1,2,3] 他们的组合方式的个数是相同的。 基于这个我们的代码方案就浮出水面了。

接下来写代码就是一次ac了

```
class Solution:
    def numTrees(self, n: int) -> int:
        nums_store = [0] * (n+1)
        
        nums_store[0] = 1
        
        
        for i in range(1,n+1):
            
            tmp_count = 0
            
            for j in range(1,i+1):
                
                tmp_count +=  nums_store[j-1] *  nums_store[i-j]
            nums_store[i] = tmp_count
        
        return nums_store[n]
        
```
网上看了别人写的代码，跟我的思路是一样的，我可没抄他们的，我是自己想的。。。。

```
class Solution:
    # @return an integer]
    # 1:05
    def numTrees(self, n):
        count = [0] * (n + 1)
        count[0] = 1

        for i in range(1, n + 1):
            for j in range(0, i):
                count[i] += count[j] * count[i - j - 1]

        return count[n]
```







