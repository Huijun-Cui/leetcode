这个题乍一看，排序问题，nlog(n),但是题目下方提示中给出了一个o(2n) 的时间复杂度，并要求用o(n) one-pass\
的程序做出来

这个题我想用的方法是，通过移动前后指针，让前指针左边的数都是0 让后指针右边的数都是1，这有点像快快速排序，但是\
真正想实现的时候，思路不是很清晰。。。 我觉得我有必要把快速排序部分再看一看。。。先把这个题做出来再说吧。。。 
这种思路下，我最终是没有想出来，看看答案吧 shit ...

我首先看到的代码是下面这样
```
class Solution:
    # @param A a list of integers
    # @return nothing, sort in place
    def sortColors(self, A):
        i = 0
        for j in range(len(A)):
            if A[i] == 0:
                A.insert(0, A.pop(i))
            elif A[i] == 2:
                A.append(A.pop(i))
                i -= 1
            i += 1
```
这个代码写的明显不符合要求，这个是时间复杂度为O(n**2)的复杂度

我又看到了另一个答案，这个就是我一直要寻求的方法，但是没有实现出来的

```
class Solution:
    def sortColors(self, nums):
   
        lowval = 0
        highval = 2

        lowi = 0
        highi = -1
        curi = 0

        def swap(i,j):
            tmp = nums[i]
            nums[i] = nums[j]
            nums[j] = tmp

        for _ in range(len(nums)):

            if nums[curi] <= lowval:
                swap(lowi,curi)
                lowi += 1
                curi += 1
            elif nums[curi] >= highval:
                swap(curi,highi)
                highi -= 1
            else:
                curi += 1


```

唉，难受。。。。  这个代码的逻辑应该好好学一学

理解这个逻辑最终总结的就是下面的一句话

上面程序通过swap 这样操作，保证我们的数组是inplace 操作，并且不会丢数据 。 同时用lowix,highix 来保证在lowix左边和\
highix右边的数据都是0和2，同时这个范围是不断减少的，保证最后的结果收敛（循环停止，我可能是深度学习学多了。。。）






