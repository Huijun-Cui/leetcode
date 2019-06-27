这个题目，我看时间复杂度是 n**n的级别，也就没有再考虑时间复杂度，直接上递归

```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        def func(nums,path_list = [],ix_list = [],ret = []):
            if len(path_list) == len(nums):
                ret.append(path_list)
                return ret
            for i in range(len(nums)):
                if i not in ix_list:
                    func(nums,path_list + [nums[i]],ix_list+[i],ret)
        path_list = []
        ix_list = []
        ret = []
        func(nums,path_list,ix_list,ret)
        return ret
```

做的也挺顺手 ，网上有很多精简的代码 ，但是我觉得太炫，时间复杂大家都差不多，那就都是好代码， 反而是那种太炫的代码不容易理解的话，反而不是好代码