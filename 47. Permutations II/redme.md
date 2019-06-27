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


