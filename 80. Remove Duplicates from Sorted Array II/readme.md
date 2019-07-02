这个题，首先想到的思路是用O(n**2)的时间复杂度去完成，看了一下discussion ，搜寻关键字O ，发现他们是用O(n)\
的时间复杂度完成的。 基于此我就想到了 swap操作，同这个方法确实是可以用O(N)的时间复杂度完成。

代码一次提交就ac了，但是只 beat掉 43.31%，以下是代码
```
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        import copy
        cur_ix = 0
        insert_ix = 0
        while cur_ix < len(nums):
            if insert_ix >1 and nums[cur_ix] == nums[insert_ix-1] and nums[cur_ix] == nums[insert_ix-2]:
                cur_ix +=1
                continue
            else:
                nums[cur_ix],nums[insert_ix] = nums[insert_ix],nums[cur_ix]
                cur_ix +=1
                insert_ix +=1
        return insert_ix

```
我的代码最后又 while insert_ix < length ，我之前用的是 nums = nums[insert_ix]， 但是这么写总会把insert_ix后面的元素\带进数组里面

我看了其他人怎么写
```
class Solution(object):
    def removeDuplicates(self, nums):
        tail = 0
        for num in nums:
            if tail < 2 or num != nums[tail - 1] or num != nums[tail - 2]:
                nums[tail] = num
                tail += 1
        return tail
```
看完这个代码我才知道，自己刚才写的程序傻了，为什么要用 swap操作呢，这个跟75 题里面sort colors问题是不一样的啊,\
在sort colors里面值不能丢弃，所以用swap，而我们这个任务里面值是可以丢弃的