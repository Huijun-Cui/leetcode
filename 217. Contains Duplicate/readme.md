这是一道easy题，这种题应该用更高效的方式去解才有意义

有一个O(n),O(n)的算法就是用集合的方式


beat 59.86%  还能更快吗？
```
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        data = set()
        
        for item in nums:
            if item not in data:
                data.add(item)
            else:
                return True
        return False
```

看了solution 这个就是最快的问题解决方式了