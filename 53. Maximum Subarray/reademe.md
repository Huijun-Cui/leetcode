这个题目有在剑指offer里面有，所以写起来很顺利

```
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        
        max_num = -8888888888888888
        acc_num = 0
        for i,item in enumerate(nums):
            if acc_num >= 0:
                acc_num +=item
            else:
                acc_num = item
            if acc_num > max_num:
                max_num = acc_num
        return max_num
```