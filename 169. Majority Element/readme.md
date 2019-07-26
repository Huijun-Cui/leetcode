
这个题可以用 O(N),O(N) space做出来

也可以用 nlog(n) 做出来 O(1) space




```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        nums.sort()
        
        return nums[len(nums)//2]
```

```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        from collections import defaultdict
        
        data = defaultdict(int)
        
        for item in nums:
            data[item] +=1
            if data[item] > len(nums) //2:
                return item
```