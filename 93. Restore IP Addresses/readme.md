这个题首先要知道什么是合法的IP地址，就是每个点划分的值数字要小于255,大于0 就不用考虑了，因为给的都是正数,这个题还是像\
之前做的Decode Ways的方法，考虑怎么用动态规划做吧

按照这个思路我写了如下代码：这个代码我写完之后才感觉，写的并不是动态规划，但是目前的问题是这个代码报错

```
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        global ret
        ret = []
        def func(s,path):
            if len(path) ==3:
                if int(s) <=255:
                    tmp = path + [s]
                    ret.append('.'.join(tmp))
                return 
            for i,item in enumerate(s):
                if int(s[:i+1]) <= 255 and i+1 < len(s):
                    func(s[i+1:],path + [s[:i+1]])
        func(s,[])
        return ret
Input: "010010"
Output: ["0.1.0.010","0.1.00.10","0.1.001.0","0.10.0.10","0.10.01.0","0.100.1.0","01.0.0.10","01.0.01.0","01.00.1.0","010.0.1.0"]
Expected: ["0.10.0.10","0.100.1.0"]

```
主要是有些并不是合法的数字，shit,我还要写一个判断是不是合法数字的函数功能，这个写好之后我很可能再次面临超时的报错,\
那个时候再改成动态规划写一下

代码提交后，没有超时，但是只beat 5.49%的代码,以下是提交代码
```
class Solution:
    def is_valid(self,s):
        if s[0] =='0' and len(s) > 1:
            return False
        else:
            return True
        
        
    def restoreIpAddresses(self, s: str) -> List[str]:
        global ret
        ret = []
        def func(s,path):
            if len(path) ==3:
                if self.is_valid(s) and int(s) <=255:
                    tmp = path + [s]
                    ret.append('.'.join(tmp))
                return 
            for i,item in enumerate(s):
                if int(s[:i+1]) <= 255 and i+1 < len(s) and self.is_valid(s[:i+1]):
                    func(s[i+1:],path + [s[:i+1]])
        func(s,[])
        return ret
```
接下来我想试着用动态规划来做一下，这种问题时间复杂度算着有点蒙啊。。。。

我突然又觉得我实现的这个程序是动态规划，因为我用了前面积累的结果 path啊 ，我看了网上的代码，跟我写的思路一样，如下：
```
class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        res = []
        self.dfs(s, 0, 0, "", res)
        return res
        
    def dfs(self, s, start, level, path, res):
        if level == 4:
            if start == len(s):
                res.append(path[:-1])
            return
        for l in xrange(1, 4):
            if start + l <= len(s):
                if l == 1: 
                    self.dfs(s, start+l, level+1, path+s[start:start+l]+".", res)
                elif l == 2 and s[start] != "0": 
                    self.dfs(s, start+l, level+1, path+s[start:start+l]+".", res)
                elif l == 3 and s[start] != "0" and int(s[start:start+l]) <= 255:
                    self.dfs(s, start+l, level+1, path+s[start:start+l]+".", res)
```

我猜测，我beat掉代码的数量少的原因是大部分人没有自己写这个代码，而是拿别人答案提交的