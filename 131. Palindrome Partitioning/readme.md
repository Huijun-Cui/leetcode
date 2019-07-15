这个题如果把所有substring遍历出来，时间复杂度很高，那个数学表达式我算不出来。。。

时间复杂度我算出来得是 O(2 **n * n)  这种时间都咋都肯定是不行得

前面也有一个这样得题吧，记得前后指针 用O(N) 就能算出来 这个题难点是怎么遍历substring时间复杂度有点高

我突然获得灵感，这个也是可以用 类似于层序遍历得思想做得，对一个字符从前向后读，如果是Palindrome,那就放入path_list,然后把剩余得字符再递归 时间复杂度大概是是  O（n\*\*4）感觉这个时间复杂度仍然是高，看了一下disscussion，他们得时间复杂度是O(2\*\*N) 这个我就表示怀疑了，我估计他们用得方法是就是我第一种提出来得方法吧，他们没有算进去 判断是不是 Palindrome的时间复杂度吧，那个时间复杂度是O(n)啊。

我就按照我的思路搞一下

一次提交ac 但是beat 51.97% 比较慢啊

```
class Solution:
    
    
    def partition(self, s: str) -> List[List[str]]:
        
        ret = []
        
        def isPalindrome(_s):
            return _s == _s[::-1]
        
        
        def func(_s,path_list):
            if len(_s) == 0:
                ret.append(path_list)
                return
            
            for i,item in enumerate(_s):
                if isPalindrome(_s[:i+1]):
                    func(_s[i+1:],path_list + [_s[:i+1]])
        
        func(s,[])
        return ret
```

看了一下别人的代码，思路跟我是一样的，我这个代码是一次ac   别人说这个代码时间复杂度是O(n**2) 这个明显是不可能的，也有人说是 O（2 **n）的时间复杂度，室友说的是有道理的，如果按照最坏的情况来考虑，就有 2 **N种结果，所以这个是 O(2 **N * N）