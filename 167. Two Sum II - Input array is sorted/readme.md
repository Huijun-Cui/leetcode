这个题 不是跟之前的2 su 一样吗？ 有什么区别吗？

怎么把排序这个信息应用起来呢？ 

我真的是蠢了。。。。。  今天状态不好，不刷题了。。。

今天起来，代码一次ac

```
class Solution(object):
    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        i = 0
        
        j = len(numbers)-1
        
        while i<j:
            
            if numbers[i] + numbers[j] == target:
                return [i+1,j+1]
            elif numbers[i] + numbers[j] > target:
                j -=1
            else:
                i +=1
        return []
```


这个题还可以考虑一下binary search 怎么做

其实这种情况下是可以用n*log(n) 来做的，挑出一个值，然后用log(n)的时间复杂度去查找，这个没意思，不去考虑了