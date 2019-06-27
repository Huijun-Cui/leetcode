做这个题目，我觉得时间复杂度有点高了唉， 在广度优先遍历的时候有有了一个  nums[i] not in data_store 的判断，我没有想到有什么好的解决方式，包括i not in ix_list 这种操作在上一个题是beat掉70% 所以没怎么在意 ，看看别人怎么写的吧 



class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        def func(nums,path_list = [],ix_list = [],ret = []):
            if len(path_list) == len(nums):
                ret.append(path_list)
                return ret
            data_store = []
            for i in range(len(nums)):
                if i not in ix_list and nums[i] not in data_store:
                    data_store.append(nums[i])
                    func(nums,path_list + [nums[i]],ix_list+[i],ret)
        path_list = []
        ix_list = []
        ret = []
        func(nums,path_list,ix_list,ret)
        return ret

以下是网上看到的解决方案 
```
def permuteUnique(self, num):
    if not num:
        return []
    return self.permute(sorted(num))
    
def permute(self, num):
    if len(num) == 1:
        return [num]
        
    ret = []
    for index, elt in enumerate(num):
        # 这行代码的作用是在深度优先遍历的时候要保证unique
        if index > 0 and num[index - 1] == elt:
            continue
        # 这个代码的巧妙之处是把自己扣扣出来，然后在剩下的文本中继续做permute，这个方法我也想过，但是没想出来，这种用法# 在 46题里面也出现过，对于这个问题，可能这种做法是最合适的方法，但是真的觉得这是一种套路。
        ret += [[elt] + p for p in self.permute(num[:index] + num[index + 1:])]
    return ret
```
