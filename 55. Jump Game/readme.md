这个题目，我刚开始看到的时候经历了以下几种思路

1. 没思路
2. 归并算法 - 基于这种思想我写了 O(N**2)的算法，75个例子通过了74个， 最后一个例子超时了，我想不出答案
```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        if len(nums) <= 0:
            return True
        
        root = [-1] * len(nums)
        root[0] = 0
        for ix,item in enumerate(nums):
            max_step = item
            while max_step >0:
                if ix + max_step >= len(nums):
                    max_step -=1
                    continue
                root[ix+max_step] = root[ix]
                max_step -=1
        return root[-1] == 0   
```

3. 看了 solution,我没有看完 我已经有答案了。写了如下代码，beat 100%,我这个代码其实跟soluton写的不一样，而且我这个加了break的原因比他的代码还要快，这也是能beat 100%的原因

```
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        max_ix = 0 
        for i,item in enumerate(nums):
            if i <=max_ix:
                if i + item > max_ix:
                    max_ix = i + item
            else:
                break
        return max_ix >= len(nums) - 1
```