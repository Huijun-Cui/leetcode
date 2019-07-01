这个题拿过来，我就知道可以用函数递归来做，但是前面几次用函数递归的经验来看，速度太慢，在这个题上我试试不用\
函数递归的方式，就像77题一样

这个题，我最终是做出来了，做的不是很顺利，最终的结果44ms,beat 59.99%,以下是代码
```
class Solution:
    def subsets(self, nums):
        ret = []
        i = 0

        stack = [1] * len(nums)
        pre_flag = 0
        while len(ret) < 2 ** len(nums):
            if len(stack) == len(nums):
                ret.append([nums[i] for i, item in enumerate(stack) if item == 1])
                while len(stack):
                    pre_flag = stack.pop()
                    if pre_flag:
                        break
                stack.append(0)

            elif len(stack) < len(nums):
                stack.append(1)
        return ret
```
这其实像 树L-root-R遍历 ，我找规律这块用了很长时间。 
后来我发现的一个很蛋疼的问题，用函数递归做的，速度比我的代码块
```
class Solution:
    def subsets(self, nums):
        res = []
        self.dfs(sorted(nums), 0, [], res)
        return res

    def dfs(self, nums, start, path, res):
        res.append(path)
        for i in range(start, len(nums)):
            self.dfs(nums, i+1, path+[nums[i]], res)
```
我看了一下测试样例只有10个，我估计是测试样例太少的原因吧