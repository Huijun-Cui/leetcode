这个题，思路挺清晰，两次提交就ac了，只beat了 19.65的代码，以下为代码,耗费的时间是740ms
```
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        global ret
        ret = []
        def func(num_list,path,ret):
            if len(path) == k:
                ret.append(path)
                return
            else:
                for i,item in enumerate(num_list):
                    func(num_list[i+1:],path + [item],ret)
        num_list = [i+1 for i in range(n)]
        
        func(num_list,[],ret)
        
        return ret
```
在网上看到下面的代码 运行时间128ms, 这个代码真的是精彩，如下：
```
class Solution:
    def combine(self, n, k):
        stack = []
        res = []
        l, x = 0, 1
        while True:
            
            if l == k:
                res.append(stack[:])
            if l == k or n-x+1 < k-l:
                if not stack:
                    return res
                x = stack.pop() + 1
                l -= 1
            else:
                stack.append(x)
                x += 1
                l += 1
```

这个代码和我的代码 时间复杂度是相同的，但是这个程序没有用函数递归，直接用一个stack就完成了递归的功能，\
这是这个代码快的原因。 这个代码最难想的地方是 n-x+1 < k- 1 ，这个需要深刻地理解整个堆栈变化的规律，这是个好代码，要\
以后也经常看看