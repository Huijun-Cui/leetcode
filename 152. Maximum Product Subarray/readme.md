这个题我想到的就是，一直累积乘，每次值是正值就更新最大值，时间复杂度是O(n)

这个题我真的是总是做到以为自己懂了，然后提交出错之后再改，前前后后改了很多，最终我的时间复杂度是O(n),空间复杂度是O(1),
但是就这样还只 beat 掉 10.89%的时间复杂度，  25%的空间复杂度。  

以下代码是最终的ac代码

```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        ret_max = -8888888888888888888888
        
        pre_max_num = -888888888888888888
        
        pre_min_num = 888888888888888888
        
        for item in nums:
            
            if item >= 0:
                
                pre_max_num = max(item * pre_max_num,item)
                
                pre_min_num = min(item* pre_min_num,item)
                
            else:
                
                _max_num = max(item * pre_min_num,item)
                
                pre_min_num = min(item * pre_max_num,item)
                
                pre_max_num = _max_num
            
            if pre_max_num > ret_max:
                    ret_max = pre_max_num
                
                
        return ret_max
```

由于这个题我用了很长时间写了多个版本，我把这个过程记录下来


我刚开始想的很简单，我觉得只要把路径上的值全部累乘就可以达到最大值，也就是说我当时认为最大值一定来自所有路径的累乘，其实这种思想只适用于有偶数个 负数的情况下
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        max_num = 0
        
        num_store = 1
        
        i = 0
        
        while i < len(nums):
            
            if nums[i] == 0:
                i +=2
                num_store = 1
            else:
                num_store *= nums[i]
                
                if num_store > max_num:
                    
                    max_num = num_store
                i +=1
        return max_num
        
```

我的第二版代码如下，就是判断累乘有没有让结果比当前数大，代码如下：

```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        max_num = -8888888888888888
        
        num_store = 1
        
        for item in nums:
            
            if num_store * item > item:
                num_store *= item
            else:
                num_store = item
            
            if num_store > max_num:
                max_num = num_store
        return max_num
```

这个思路明显不对，累乘如果乘以一个负数值会变小，但是后面再遇到负数很可能就是我们要求的结果


第三个版本跟第二个版本如出一辙，当然也是错误的

```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        max_num = -88888888888888888888
        
        num_store = 1
        
        for item in nums:
            
            if max(item,item * num_store) > max_num:
                max_num = max(item,item * num_store)
            
            
            if item == 0:
                num_store = 1
            num_store *= item
        return max_num
```

第四个版本算是上了轨道了，我用动态规划的思想，如果当前数是负数，那么最大值肯定是 乘以前一时刻的最小值，相对应地，最小值肯定是乘以前一个时刻最大值。  如果当前是正数，情况正好相反。  我写了下面代码

但是代码是错误地，有bug，我把最后一个值地最大值作为返回值
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        max_num = -888888888888888888
        
        min_num = 888888888888888888
        
        for item in nums:
            
            if item >= 0:
                
                max_num = max(item * max_num,item)
                
                min_num = min(item* min_num,item)
            else:
                
                _max_num = max(item * min_num,item)
                
                min_num = min(item * max_num,item)
                
                max_num = _max_num
        return max_num
```

第五版就是我的ac 代码了

```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        
        ret_max = -8888888888888888888888
        
        pre_max_num = -888888888888888888
        
        pre_min_num = 888888888888888888
        
        for item in nums:
            
            if item >= 0:
                
                pre_max_num = max(item * pre_max_num,item)
                
                pre_min_num = min(item* pre_min_num,item)
                
            else:
                
                _max_num = max(item * pre_min_num,item)
                
                pre_min_num = min(item * pre_max_num,item)
                
                pre_max_num = _max_num
            
            if pre_max_num > ret_max:
                    ret_max = pre_max_num
                
                
        return ret_max
```

网上看到一个代码，真的是精彩，真的是服气

```
  def maxProduct(self, A):
        B = A[::-1]
        for i in range(1, len(A)):
            A[i] *= A[i - 1] or 1
            B[i] *= B[i - 1] or 1
        return max(A + B)
```

作者用了前向和后向的累乘， 这就解决了负数是奇数个的情况，如果负数是偶数了那就是全部数字乘起来，当然如果中间有零，那就要另外讨论了


网上又看到另外一个版本思路是跟我一样的。 但是代码写的比我简练

```
class Solution(object):
def maxProduct(self, nums):
    """
    :type nums: List[int]
    :rtype: int
    """
    MAX = MIN = res = nums[0]
    for i in range (1, len(nums)):
        MAX, MIN = max(MAX*nums[i], MIN*nums[i],nums[i]), min(MAX*nums[i],MIN*nums[i],nums[i])
        res = max(MAX, res)
    return res
```