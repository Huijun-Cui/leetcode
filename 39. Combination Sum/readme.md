这个题目 我想了很久，好久没有也递归程序了，这个题目其实是一个 有限状态自动机的功能，写出来的程序自己不是很满意，时间复杂/度也是比较高，里面有一个  if ix_list not in result这样的代码，所以运行时间也是非常慢

```
class Solution:
    def fuc(self, candidates, target, sum_num, ix, ix_list, result):
        # print("sum_num = {} ix = {} ix_list = {} result = {} ".format(sum_num,ix,ix_list,result))
        if sum_num == target:
            if ix_list not in result:
                result.append(ix_list)
            return
        elif sum_num > target:
            return
        if ix < len(candidates):
            self.fuc(candidates,target,sum_num+candidates[ix],ix,ix_list + [candidates[ix]],result)

        if ix < len(candidates) - 1:
            self.fuc(candidates, target, sum_num, ix+1, ix_list, result)

    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """

        result = []

        candidates.sort()

        sum_num = 0


        for ix in range(len(candidates)):
            ix_list = []
            self.fuc(candidates, target, sum_num, ix, ix_list, result)

        return result
```

在 discussion 里面发现了这么一个 精简的代码 
```
def combinationSum(self, candidates, target):
    res = []
    candidates.sort()
    def dfs(nums, target, index, path, res):
        if target < 0:
            return  # backtracking
        if target == 0:
            res.append(path)
            return 
        for i in xrange(index, len(nums)):
            if nums[i] > target: break #improvement
            dfs(nums, target-nums[i], i, path+[nums[i]], res)
    dfs(candidates, target, 0, [], res)
    return res
```
整体思路是跟我很想的 ，只是他没有像我那样 if ix_list not in resul  这样的代码 ，这个代码之所以避免了这种 路径是否重复的判断，是因为他是用广度优先遍历，这种遍历下生成的路径是 unique的 ，而我写的代码他不是广度优先遍历，而是一个 有限状态自动机的实现，每次都是从某个节点作为其实节点，开始遍历，这种情况下会生成相同的路径 

