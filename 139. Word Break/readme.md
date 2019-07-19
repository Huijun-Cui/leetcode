感觉这个题又涉及到kmp算法了吧 ，之前有一道kmp算法题，我没有做唉。。。。

这个题我的思路就是根据wordDict里面的词把输入字符串 replace掉，然后最终判断字符串是不是为空

但是这里涉及到字符串查找的问题，要用kmp算法，所以我应该再复习一下kmp算法

之前leetcode里面的kmp算法是 28题， 

我已经把KMP算法看懂了，这两天一直在调生物钟，一道晚上7点左右就困的不行了，喝了咖啡之后瞬间满血复活。

KMP算法这次我敢说看懂了，是因为我在看算法的同时想明白了怎么用O(N)的时间构建next数组

更新next数组的代码如下：

```
def next_array(s):
    next = [0] * len(s)

    for i in range(1,len(s)):
        if s[i] == s[next[i-1]]:
            next[i] = next[i-1] +1
        else:
            next[i] = 0
    return next

def kmp(s,p,next):

    s_start = 0
    match_ix = 1
    while s_start + len(p) < len(s):
        if s[s_start] != p[0]:
            s_start +=1
            match_ix = 1
            continue

        if match_ix == len(p):
            return True

        if s[s_start+match_ix] == p[match_ix]:
            match_ix +=1
        else:
            s_start += match_ix - next[match_ix-1]
            match_ix = next[match_ix-1]
    return False

```

在leetcode做第28题，提交几次之后发现，我的next_array 函数是错误的，是算法思想错了，shit!!!! 在以下case里会发生错误

```
aabaaac
```

看了网上的教程，终于把代码ac了，这个题可能是我见过的最难的了以下是我的代码
```
class Solution:
    
    def next_array(self,s):
        
        _next = [0] * len(s)
        pre_len = 0
        i = 1
        while i < len(s):
            if s[i] == s[pre_len]:
                pre_len +=1
                _next[i] = pre_len
                i +=1
            else:
                if pre_len:
                    pre_len = _next[pre_len-1]
                else:
                    _next[i] = 0
                    pre_len = 0
                    i +=1
        return _next
                
        
    def kmp(self,s,p,_next):
        
        s_start = 0
        
        match_ix = 1
        
        while s_start + len(p) <= len(s):
            
            if s[s_start] != p[0]:
                s_start +=1
                match_ix = 1
                continue
            
            if match_ix == len(p):
                return s_start
            
            if s[s_start+match_ix] != p[match_ix]:
                s_start += match_ix - _next[match_ix-1]
                match_ix = _next[match_ix-1]
            else:
                match_ix+=1
        return -1
            
    
    def strStr(self, haystack: str, needle: str) -> int:
        
        if len(needle) == 0:
            return 0
        if len(haystack) == 0:
            return -1
        _next = self.next_array(needle)
        
        return self.kmp(haystack,needle,_next)
```

网上看了一个代码，代码特别短，而且比我的方案要快很多

```
class Solution:
    # @param haystack, a string
    # @param needle, a string
    # @return an integer
    def strStr(self, haystack, needle):
        if haystack == needle == '':
            return 0

        n = len(needle)
        
        for i in range(len(haystack) - n + 1):
            if haystack[i:i+n] == needle:
                return i

        return -1
```

可是这个版本的代码，我之前写是超时的啊

```
class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not len(needle):
            return 0
        if len(needle) > len(haystack):
            return -1
        ix1 = 0 
        while ix1 < len(haystack):
            ix2 = 0
            _ix1 = ix1
            while _ix1 < len(haystack) and ix2 < len(needle):
                if haystack[_ix1] != needle[ix2]:
                    break
                ix2 +=1
                _ix1 +=1
            if ix2 == len(needle):
                return ix1
            ix1 +=1
        return -1
```

网上我又看了另一个kmp算法，写的很精简

```
    def kmp(self,T,P):
        
        next = self.makeNext(P)
        
        i = 0 #cursor in T
        q = 0 #cursor in P
        while i < len(T):
            while q > 0 and P[q] != T[i]:
                q = next[q-1]
            
            if T[i] == P[q]:
                q += 1
            
            if q == len(P):
                return i - len(P) + 1
            i+=1
        
        return -1
```

这个算法写的太精彩了，对kmp算法的理解很到位，kmp算法的实质就是p_string的指针倒退策略，最换的情况指针倒退len(s)-2,一般情况下倒退的数比这个小，由此提高了算法的效率。 而倒退的值是存储在next数组里面 。 而我之前想的还要考虑 m_string里的start_ix ,  其实是没必要的


现在回过头来看139题，我的思路就是遍历wordDict，在s里面查找字符串，并删除，用剩余的字符串s,再循环前面的操作，知道字符串为空。时间复杂度不好算。。。

可是这种时间复杂度我觉得高，而且其实这思想的算法是有bug的

这个题我觉得可以用动态规划来做，同时题里面wordDict是列表的形式，我们可以把他换成字典的结构这样的话查找的时间复杂度是O(1)

第一版本的代码如下，结果wrong answer

```

Input
"aaaaaaa"
["aaaa","aaa"]
Output
false
Expected
true




class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        data = {}
        for item in wordDict:
            data[item] = 1
        def func(_s):
            
            if len(_s) == 0:
                return True
            
            for i,item in enumerate(_s):
                
               
                
                if _s[:i+1] in data:
                    
                    return func(_s[i+1:])
            return False
        return func(s)
                    
```
上面的代码改了bug之后代码如下，超时了。。。

```
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        
        data = {}
        for item in wordDict:
            data[item] = 1
        def func(_s):
            flag = False
            if len(_s) == 0:
                return True
            
            for i,item in enumerate(_s):
                
               
                
                if _s[:i+1] in data:
                    
                    flag = flag or func(_s[i+1:])
            return flag
        return func(s)
                    
```

这个题完全没思路要怎么去加快速度，看看discussion吧 。。。。 

网上看到这样的代码

```
def wordBreak(self, s, wordDict):
    dp = [False] * (len(s)+1)
    dp[0] = True
    for i in xrange(1, len(s)+1):
        for j in xrange(i):
            if dp[j] and s[j:i] in wordDict:
                dp[i] = True
                break
    return dp[-1]
```

唉真的是自愧不如啊。。。。  






