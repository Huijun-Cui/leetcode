这个题没有给出时间复杂度的要求，但是说要用三种方法完成，那我就试试

有O(kn) 时间复杂度

还有 O（k）的时间复杂度，我觉得这种方式最快了吧 就用这个方法搞吧

我的第一个版本的代码如下，写错了，因为我没准确题目的意思

```
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        k = k % len(nums)
        
        pre_ix = 0
        
        rear_ix = len(nums) - k
        
        while pre_ix < k:
            
            nums[pre_ix],nums[rear_ix] = nums[rear_ix],nums[pre_ix]
            
            pre_ix +=1
            
            rear_ix +=1
        return
```

我觉得不会有O（k） 这种算法吧，

但是可以有O(N) 的算法，就是找数学规律  这个题我想不出来 O(n)的方法，也想不出来有什么三种方法


看了discussion，这个题是用循环replacement做的 ，真的是太妙了，学习了，我发现easy题往往可以学到更宝贵的经验

在实现循环replacement的时候，我还是发现了问题

1 2 3 4 5 6 7 ， k =2的时候 7 会换到 1原来的位置，这个时候刚好置换了一圈，下一步应该从2开始，但是我们怎么知道这个时候转了一圈呢？ 我们不可能给每个位置都设置一个flag,题中要求空间复杂度是O(1)。 我之前想的方法是 如果索引值大于数组边界，说明已经转了一圈了，但是转了一圈不代表一定要停止，比如：
1 2 3 4 5 6 7 ， k = 3的时候 。

看了一下discussion， 他是记录了开始的位置，当再次遍历到开始的索引的时候，就从接下来的索引值开始遍历。 

我发现好弱，这么一个直观，简单的方法为什么我没有意识到？ 开始撸代码

```
class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        
        start_ix = 0
        
        p_cur = k
        
        num = nums[0]
        
        count = 0
        
        length = len(nums)
        
        while count < length:
            
            num,nums[p_cur%length] = nums[p_cur%length],num
            
            if p_cur%length == start_ix:
                start_ix +=1
                num = nums[start_ix%length]
                p_cur = start_ix + k
            else:
                p_cur += k
            
            count +=1
            
```









