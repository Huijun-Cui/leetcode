这题，刚拿过来想到的就是除法，结果题目中不让用除法。。。

我用了前向，后向数组，然后写了如下代码，不确定我这样写是不是占用了额外的空间，beat 8.59%, 5.26%

```
class Solution:
    def productExceptSelf(self, nums):

        ret = [0] * len(nums)

        for i, item in enumerate(nums):
            if i == 0:
                ret[i] = [nums[0], None]
            else:
                ret[i] = [nums[i] * ret[i - 1][0], None]
        for i in range(len(nums) - 1, -1, -1):
            if i == len(nums) - 1:
                ret[i][1] = nums[-1]
            else:
                ret[i][1] = nums[i] * ret[i + 1][1]

        for ix in range(len(nums)):
            if ix -1 < 0:
                forward = 1
            else:
                forward = ret[ix-1][0]
            if ix + 1 >= len(nums):
                backward = 1
            else:
                backward = ret[ix+1][1]
            nums[ix] = forward * backward
        return nums
```

这个问题里面提到，要用O(1)的空间复杂度， 这个问题我没有想出来

后来看到答案说先在output array上存 forward 数据，然后在backward 的过程中更新output array 就可以了