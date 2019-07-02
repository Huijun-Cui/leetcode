这个题看了之后觉得是一个O(n*m)的时间复杂度的问题啊，看看discussion 他们的时间复杂度是多少，他们是用O(n)做出来的，\
那让我再思考一下
我隐约感觉这应该是swap方法，两部分内部已经排好顺序，通过某种顺序swap在O(n)时间完成排序，但是这种方法很骚，也没听过，\
想想别的方法
这是个easy题啊，但是O(n)时间复杂度算法想不出来....  会不会是 solution里面的给算错了，再次看了一下discusison确实\
里面的人都是用O(N) 时间复杂度做出来的
我突然想到，这个题确实可以用O(n)时间复杂度做出来，这个跟排序链表merge是一样的，链表那个任务里是可以用自己创建一个新\
的链表，其实不创建也可以完成这个操作的
我特么又灵光一现，pop() append() 不都是 O(1)时间复杂度吗？ 用这个思路去想想，对了就是用这个方法做的，撸代码

可是我又想到pop(0)貌似不是 O(1)时间复杂度啊
得了，我注意到 提示里面说 
```
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2
```
那我们就不pop(o)了

```
class Solution:
    def merge(self, nums1, m: int, nums2, n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        ix1 = 0
        ix2 = 0
        nums1_len = len(nums1)
        nums2_len = len(nums2)

        while ix1 < m and ix2 < n:
            if nums1[ix1] <= nums2[ix2]:
                nums1.append(nums1[ix1])
                ix1 += 1
            else:
                nums1.append(nums2[ix2])
                ix2 += 1

        while ix1 < m:
            nums1.append(nums1[ix1])
            ix1 += 1
        while ix2 < n:
            nums1.append(nums2[ix2])
            ix2 += 1
        nums1 = nums1[nums1_len:]
```

这个代码 nums1[nums1_len:] 结果是没问题得，但是为什么不能覆盖nums1啊 无语


网上有个答案是下面这样

```
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        while m > 0 and n > 0:
            if nums1[m - 1] > nums2[n - 1]:
                nums1[m + n - 1] = nums1[m - 1]
                m -= 1
            else:
                nums1[m + n - 1] = nums2[n - 1]
                n -= 1
        nums1[:n] = nums2[:n]
```
这个代码写得太漂亮了，我为什么没有想到这点，因为我当时死脑筋，只想到merge是用最小值merge，其实也是可以用最大值merge啊
虽然我也写出了O(n)时间复杂度，但是python list inplace modify 有些问题