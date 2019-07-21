这个题之前是做过类似的题，记得当时写的也不是很顺利，当时是查找数字，而这个是找最小值。
很显然这个题可以用O(N)时间做出来，但是我们要想怎么用log(N)的时间做出来

最小值的特点是 比左右两个数都小

我现在初步的思想是如果 选中的值在单调区间，那就直接返回最左边的坐标，如果不是在单调区间那就在有半取找

找下规律的话是这样
以 [4,5,6,7,0,1,2] 为例子

如果不在单调区间
[4,5,6,7] 这个区间里的值都是比两端的值大，应该往右边区间找
[0,1,2] 都比两端值小，应该往左边区间找

如果在单调区间，直接返回这个区间的最小值，前提是不能把但单调区间锁定在[4,5,6,7]这里

这个题我一次ac 了
```
class Solution:
    def findMin(self, nums: List[int]) -> int:
        
        s_ix = 0
        
        e_ix = len(nums) -1
        
        while s_ix <= e_ix:
            
            mid = (s_ix + e_ix) //2 
            
            if nums[s_ix] <= nums[mid] <= nums[e_ix]:
                return nums[s_ix]
            elif nums[s_ix] >= nums[mid] and nums[e_ix] >= nums[mid]:
                e_ix = mid
            elif nums[s_ix] <= nums[mid] and nums[e_ix] <= nums[mid]:
                s_ix = mid + 1
        
```

但是中间考虑 mid >= 还是 > 这种条件的时候真的好难想啊，这个有什么诀窍码？ 

看了一下网上的代码，人家的代码就没有考虑等于的情况，如下

```
class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def findMin(self, nums):
        if not nums:
            return -1

        low, high = 0, len(nums) - 1
        mid = (low + high) / 2

        while low < high:
            if nums[mid] > nums[mid + 1]:
                return nums[mid + 1]
            elif nums[mid] > nums[high]:
                low = mid + 1
            else:
                high = mid
            mid = (low + high) / 2

        return nums[mid]
```