这个题 我最开始是用递归的算法做的，时间复杂度是 n ** n 然后超时了 ....

```
Last executed input ：

8
35784



class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        def func(s):
            if len(s) == 0:
                return [[]]
            if len(s) == 1:
                return [[s]]
            else:
                ret = []
                for i,item in enumerate(s):
                    for item2 in func(s[:i]+s[i+1:]):
                        ret.append([item] + item2)
                return ret
        s = ''
        for i in range(n):
            s += str(i+1)
        count = 0
        for i,item in enumerate(s):
            for item2 in func(s[:i] + s[i+1:]):
                count +=1
                if count == k:
                    return item+ ''.join(item2)
                        
```

我后来想到了 O(n)时间复杂度 ，但是写的过程中处了很多错误

主要问题还是出在没有勤debug ,以下是我的代码
```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        if n == 1:
            return '1'
        
        str_list = [str(item + 1) for item in range(n)]
        ret = []
        st_num = 1
        i = 1
        st_n = n - 1
        k -= 1
        while i <= n - 1:
            st_num *= i
            i += 1
        while len(str_list):
            ix = k // st_num
            ret.append(str_list[ix])
            str_list.pop(ix)
            k = k % st_num

            st_num //= st_n
            st_n -= 1
            if st_n == 0:
                st_n = 1

        return ''.join(ret)
```

网上看了别人的实现，思路也是这样  ，这个代码我自己写的不是很满意 ，后面再过一次吧 。。这里的实现细节，对st_n == 0的条件判断，以及 while(len(str_list))都是一些技巧 我个人觉得