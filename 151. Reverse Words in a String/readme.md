这个 一行代码 
我知道这个是因为python的便利，这个题以后再用c++写吧

```
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(s.strip().split()[::-1])
```