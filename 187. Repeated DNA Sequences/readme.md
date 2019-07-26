这个可以用kmp算法做啊， 题目中说是固定长度10， 那这个题最终是可以用 O（n**2）的时间复杂度完成，看了一下discusssion，他们是用O(N)做出来的啊。。。

突然想道了 可以用hash map的思想啊 我的晕。。。  开始撸代码

```
class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        
        ret = []
        
        from collections import defaultdict
        
        dic = defaultdict(int)
        
        i = 10
        
        while i <= len(s):
            
            dic[s[i-10:i]] +=1
            if dic[s[i-10:i]] == 2:
                ret.append(s[i-10:i])
            
            i+=1
        return ret
```

代码一次ac 