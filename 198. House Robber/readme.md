代码两次提交ac 第一次提交的代码出错了，是因为算法思想错了，以下是我的代码

```
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        
        if len(nums) <=2:
            return max(nums)
        
        max_num = max(nums[:2])
        
        i = 2
        
        while i < len(nums):
            
            nums[i] += nums[i-2]
            
            if nums[i] > max_num:
                max_num = nums[i]
            
            i +=1
        return max_num
        
```
后来发现错误了之后，我用了下面的代码 ac beat 96.33%

```
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        max_num = 0
        
        i = 0
        
        while i < len(nums):
            
            s_ix = i-4
            
            if s_ix < 0:
                s_ix = 0
                
            if i-1 > s_ix:
                nums[i] += max(nums[s_ix:i-1])
            
            if nums[i] > max_num:
                max_num = nums[i]
            i+=1
            
            
        return max_num
```

网上看了一下别人的答案，也都是用动态规划，但是这种思路不太好想啊

```
f(0) = nums[0]
f(1) = max(num[0], num[1])
f(k) = max( f(k-2) + nums[k], f(k-1) )
```


下面这个代码也不太好理解，晕。。。。。

```
class Solution:
    
    def rob(self, nums):
        
        last, now = 0, 0
        
        for i in nums: last, now = now, max(last + i, now)
                
        return now
```

网上有人对这个代码做了解释
```
class Solution(object):
  def rob(self, nums):
    # Base Case: nums[0] = nums[0]
    # nums[1] = max(nums[0], nums[1])
    # nums[k] = max(k + nums[k-2], nums[k-1])
    '''
    # Approach 1:- Construct dp table
    if not nums: return 0
    if len(nums) == 1: return nums[0]
    
    dp = [0] * len(nums)
    dp[0] = nums[0]
    dp[1] = max(nums[0], nums[1])
    for i in range(2, len(nums)):
      dp[i] = max(nums[i] + dp[i-2], dp[i-1])
    return dp[-1] # return the last element
    '''
    
    # Approach 2:- Constant space use two variables and compute the max respectively
    prev = curr = 0
    for num in nums:
      temp = prev # This represents the nums[i-2]th value
      prev = curr # This represents the nums[i-1]th value
      curr = max(num + temp, prev) # Here we just plug into the formula
    return curr
```