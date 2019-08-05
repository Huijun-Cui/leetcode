这个题很简单吧 。。。。 这个算中等？

代码一次ac,但是写这个代码的时候，需要考虑边界问题，我一直希望在解决边界问题的时候可以有一种方法论。

```
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ret = []
        
        s_ix = 0
        e_ix = 1
        while s_ix < len(nums):
            
            if e_ix < len(nums) and nums[e_ix] == nums[e_ix-1]+1:
                e_ix +=1
                continue
            else:
                if e_ix-1 == s_ix:
                    ret.append(str(nums[s_ix]))
                else:
                    ret.append("{}->{}".format(nums[s_ix],nums[e_ix-1]))
                s_ix = e_ix
                e_ix +=1
        
        return ret
```
这个代码写的时候，感觉是一个碰巧问题， 就是 if e_ix - 1 == s_ix 个时候，这段代码并不是普遍性的方法论

看了一下网上的代码，写的很精彩，有三种solution

```
class Solution:
    def summaryRanges(self, nums):
        ranges = []
        for n in nums:
            if not ranges or n > ranges[-1][-1] + 1:
                ranges += [],
            ranges[-1][1:] = n,
        return ['->'.join(map(str, r)) for r in ranges]

```

这代码太漂亮了  学习了

```
def summaryRanges(self, nums):
    ranges, r = [], []
    for n in nums:
        if n-1 not in r:
            r = []
            ranges += r,
        r[1:] = n,
    return ['->'.join(map(str, r)) for r in ranges]
```
















