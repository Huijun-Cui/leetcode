这个题解法我觉得就是 字符之间的关系一一对应，漫射关系，而不存在多对一，一对多的情况，比如：

foo 和 bar 

o-> a
o-> r

o对应了两个状态

这个题要用一个hash 字典，时间复杂度是 O(n)，空间复杂度是O(n)

以上的思路是错误的

代码如下：

```
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        data = {}
        
        for item1,item2 in zip(s,t):
            if item1 not in data:
                data[item1] = item2
            elif data[item1] != item2:
                return False
            if item2 not in data:
                data[item2] = item1
            elif data[item2] != item1:
                return False
        return True

Your input
"paper"
"title"
Output
false
Expected
true

```

基于以上的错误代码，我觉得这个题可能要算两次 ，两个方向的映射各算一次，

代码ac了，beat 49.23% 9.94%  , 明显大家不是像我这样用的2-pass
```
class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        
        data = {}
        
        for item1,item2 in zip(s,t):
            if item1 not in data:
                data[item1] = item2
            elif data[item1] != item2:
                return False
        
        
        data = {}
        
        for item1,item2 in zip(s,t):
            if item2 not in data:
                data[item2] = item1
            elif data[item2] != item1:
                return False
        
        
        return True
```


我再想想one-pass的算法，我发现我不知是要想one-pass 空间复杂度也应该降低下来，能不能用O(1)的空间复杂度呢？ 

网上看的代码，我觉得代码都挺怪的，思路也不好想

```
def isIsomorphic1(self, s, t):
    d1, d2 = {}, {}
    for i, val in enumerate(s):
        d1[val] = d1.get(val, []) + [i]
    for i, val in enumerate(t):
        d2[val] = d2.get(val, []) + [i]
    return sorted(d1.values()) == sorted(d2.values())
        
def isIsomorphic2(self, s, t):
    d1, d2 = [[] for _ in xrange(256)], [[] for _ in xrange(256)]
    for i, val in enumerate(s):
        d1[ord(val)].append(i)
    for i, val in enumerate(t):
        d2[ord(val)].append(i)
    return sorted(d1) == sorted(d2)
    
def isIsomorphic3(self, s, t):
    return len(set(zip(s, t))) == len(set(s)) == len(set(t))
    
def isIsomorphic4(self, s, t): 
    return [s.find(i) for i in s] == [t.find(j) for j in t]
    
def isIsomorphic5(self, s, t):
    return map(s.find, s) == map(t.find, t)

def isIsomorphic(self, s, t):
    d1, d2 = [0 for _ in xrange(256)], [0 for _ in xrange(256)]
    for i in xrange(len(s)):
        if d1[ord(s[i])] != d2[ord(t[i])]:
            return False
        d1[ord(s[i])] = i+1
        d2[ord(t[i])] = i+1
    return True
```

上面的主要思想其实就是 无论字符怎么变换，换成索引值之后，他们都是等价的。




