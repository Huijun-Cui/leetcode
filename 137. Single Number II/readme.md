这个题看着，完全没思路啊，这个题我在剑指offer里是见过的，但是现在想不起来了。。。。

想了好久终于想到了方案，几乎是在要放弃的时候。。。。 完全没有借助剑指offer里的思想


上面的思想是错误的，我写出了下面这个错误的代码

```
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        num = 0
        
        for item in nums:
            num ^= item
        
        for item in nums:
            num ^= item
        
        return num
```


这个问题我想不出来了,看答案吧，明天再看，好困。。。add

