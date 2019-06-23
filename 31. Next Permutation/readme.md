这个问题我想了挺久，最终用O（N）的时间复杂度做出来，看了一下之前的记录，之前是没有做出来，直接看的答案，所以通过这个题还挺获得信心的，哈哈。 以下是代码
```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 1:
            return
        ix = len(nums) - 1
        
        while ix >= 0:
            if ix < len(nums) -1:
                if nums[ix] < nums[ix+1]:
                    break
            ix -=1
        
        if ix < 0:
            nums.sort() 
        
        nums[ix+1:] = sorted(nums[ix+1:],key = lambda x:x) 
        
        ix2 = ix+1
        while ix2 <= len(nums)-1:
            if nums[ix2] > nums[ix]:
                nums[ix2],nums[ix] = nums[ix],nums[ix2]
                break
            ix2 +=1
        return 
```
这个问题，我的总结是 时刻要算算法复杂度是多少，然后对问题建模，建模完后落实细节
