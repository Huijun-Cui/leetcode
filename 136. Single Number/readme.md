这个题，我首先想到的是用哈希解法，但是题目中要求不要用额外的空间复杂度，我想到了异或

代码一次ac

```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        
        ret_num = 0
        
        for item in nums:
            ret_num ^= item
        return ret_num
```