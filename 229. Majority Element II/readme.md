这个题跟，室友给的微软面试题很像啊，但是微软那个题是给了数的范围

微软那个题我就想了半天，再看到这个题，又没思路了。。。

我觉得这个题是用hash map的思想，尝试撸代码。。


```
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        
        i = 0
        
        while i < len(nums):
            
            num = None
            if isinstance(nums[i],list):
                num = nums[i][2]
            else:
                num = nums[i]
            
            hash_ix = num % len(nums)
            
            
            while isinstance(nums[hash_ix],list) and nums[hash_ix][0] != num:
                hash_ix +=1
            
            if isinstance(nums[hash_ix],list):
                nums[hash_ix][1] +=1
            else:
                nums[hash_ix] = [num,1,nums[hash_ix]]
            i+=1
        
        ret = []
        
        for item in nums:
            
            if isinstance(item,list) and item[1] >= len(nums)//3 + 1:
                ret.append(item[0])
        return ret
```

代码这样貌似不是O(1)的时间复杂度，看看discussion  

这个题实际上是 Majority Voting Algorithm-Boyer-Moore Algorithm 的算法 也叫摩尔投票算法，比较经典了，要记住


```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # there can only be at most 2 majority elements in an array
        # find those two elements, if exist
        num1, num2 = 0, 0
        c1, c2 = 0, 0
        r = []
        for i in nums:
            if i == num1:
                c1 += 1
            elif i == num2:
                c2 += 1
            elif c1 == 0:
                num1 = i
                c1 = 1
            elif c2 == 0:
                num2 = i
                c2 = 1
            else:
                c1 -= 1
                c2 -= 1
        # verify if the elements found are the majority numbers
        c1 = 0
        c2 = 0
        for j in nums:
            if j == num1:
                c1 += 1
            elif j == num2:
                c2 += 1
        l = len(nums)
        if c1 > l / 3:
            r.append(num1)
        if c2 > l / 3:
            r.append(num2)
        return r
```

