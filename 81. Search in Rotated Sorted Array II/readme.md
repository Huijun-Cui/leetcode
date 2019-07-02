这个题之前做过啊 怎么感觉是同一个题啊，不管了，就当做第二遍，开始写代码。哦 下面又提示说这个题跟之前\
的 Search in Rotated Sorted Array 像，不同的是这个题是又重复的值，anyway ..开始写代码 ，然后他还问\
这种情况会影响 时间复杂度吗？ 他这么问，答案貌似是会影响，但我觉得不会影响时间复杂度啊。。。

程序写完了，又是无尽的wrong answer .... debug 代码中

对这种二分法问题，我总是不能一次bug free ，上次写的时候就不顺利，难受，打算借这次机会好好琢磨一下

我写的代码是这样
```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if len(nums) == 0:
            return False
        left = 0
        right = len(nums) -1
        mid = (left+right) //2

        while left < right:
            if nums[mid] <= nums[right]:
                if target == nums[mid]:
                    return True
                if target == nums[right]:
                    return True
                if target > nums[mid] and target < nums[right]:
                    left = mid+1
                else:
                    right = mid -1

            else:
                right = mid

            mid = (left + right) //2

            if nums[mid] == target:
                return True
        if nums[mid] == target:
            return True
        else:
            return False
```
在下面这个case 里面报错
```
Input: [3,1]
target: 1
Output: false
Expected: true
```
这个程序的逻辑错误在于 如果[3,1] 不是一个递增区间，程序就缩小到[3] 这个区间，最后返回False,\

我后来把程序改成了如下，因为我发现一个规律（其实就是针对上一个题的规律），得是在递增区间不匹配才能转到另外一个区间\
，我在上面写得代码一个bug是只实现了右侧区间是递增区间得情况，而没有实现左侧区间是递增区间得情况。所以就出现上面那个\
case 下得错误，[3,1] 不是连续区间，那就转到了[3] 这个时候 left == right 所以就返回 False

我又写了下面这个代码，改掉了上面那个代码得错误，
```
class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        if len(nums) == 0:
            return False
        left = 0
        right = len(nums) -1
        mid = (left+right) //2

        while left < right:
            
            if nums[mid] <= nums[right]:
                if target == nums[mid] or target == nums[right]:
                    return True
                if target > nums[mid] and target < nums[right]:
                    left = mid+1
                else:
                    right = mid -1
            elif nums[mid] >= nums[left]:
                if target == nums[mid] or target == nums[left]:
                    return True
                if target > nums[left] and target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1


            mid = (left + right) //2

            if nums[mid] == target:
                return True
        if nums[mid] == target:
            return True
        else:
            return False
```
但是在下面得例子中又报错了
```
Input: [1,1,3,1]
target: 3
Output : False
Expected: False
```

这个问题出现得原因就是因为多个1的出现，我们程序两个if 判断递增区间的  ，无法应对这种情况

对这种问题的解决办法就是，如果碰到相等的情况，那么我们就移动mid，直到不相等，这个也许就是题目一开说的会不会影响时间复杂度的问题吧，照着思路，写了下面的代码，并且最终ac了

```
class Solution:
    def search(self, nums, target: int) -> bool:
        if len(nums) == 0:
            return False
        left = 0
        right = len(nums) - 1
        mid = (left + right) // 2

        while left < right:
            if nums[mid] <= nums[right]:

                while nums[mid] == nums[right] and mid < right:
                    mid += 1
                    continue

                if target == nums[mid] or target == nums[right]:
                    return True

                if target > nums[mid] and target < nums[right]:
                    left = mid + 1
                else:
                    right = mid - 1
            elif nums[mid] >= nums[left]:

                while nums[mid] == nums[left] and mid > left:
                    mid -= 1
                    continue
                if target == nums[mid] or target == nums[left]:
                    return True

                if target > nums[left] and target < nums[mid]:
                    right = mid - 1
                else:
                    left = mid + 1

            mid = (left + right) // 2

            if nums[mid] == target:
                return True
        if nums[mid] == target:
            return True
        else:
            return False
```
看了网上的代码，解决的思路跟我是一样的

```
class Solution:
    def search(self, nums, target):
        l, r = 0, len(nums)-1
        while l <= r:
            mid = l + (r-l)//2
            if nums[mid] == target:
                return True
            while l < mid and nums[l] == nums[mid]: # tricky part
                l += 1
            # the first half is ordered
            if nums[l] <= nums[mid]:
                # target is in the first half
                if nums[l] <= target < nums[mid]:
                    r = mid - 1
                else:
                    l = mid + 1
            # the second half is ordered
            else:
                # target is in the second half
                if nums[mid] < target <= nums[r]:
                    l = mid + 1
                else:
                    r = mid - 1
        return False
```
但是运行速度比我快了一倍，可是算法思路跟我一样的啊









