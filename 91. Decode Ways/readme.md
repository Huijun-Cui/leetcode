这个问题，我刚拿过来就觉得这个是一个求subset的过程，并且从把subset中 值大于26的删除掉，\
这种做法肯定是可以，但是就是担心时间复杂度有点高，有没有更高效的方式呢？ 不管了，先拿这个实现一下，跟之前的问题\
不一样的地方是，之前那个问题元素之间可以自由组队的，但是这个是组合元素必须在位置上是连续的

这个程序其实很NLP里面的分词任务，我们就用函数递归来解决这个问题吧。

然后我写了如下的代码，结果超时了....

```
Input : "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948"

class Solution:
    def numDecodings(self, s: str) -> int:
        # word = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z"]
        # word_dic = {}
        # for item in word:
        #     word_dic[len(word_dic)+1] = item
        def func(s):
            if len(s) == 1:
                if int(s)>0:
                    return 1
                else:
                    return 0
            count = 0
            for i,item in enumerate(s):
                if 0<int(s[:i+1]) <= 26:
                    if i!=len(s)-1:
                        count += func(s[i+1:])
                    else:
                        count +=1
                else:
                    break
            return count
        
        return func(s)  

```

这个程序需要用动态规划来求解，仔细看看，我这个程序并不是动态规划的解法，接下来尝试动态规划解法

```
class Solution:
    def numDecodings(self, s: str) -> int:
        path = [1] * len(s)
        i = len(s) -1
        
        while i >=0:
            j = i+1
            count = 0
            while j < len(s):
                if 0<int(s[i:j])<=26:
                    count += path[j]
                    j+=1
                else:
                    break
            if j == len(s) and 0<int(s[i:j])<=26:
                count+=1
            path[i] = count
            i -=1
        return path[0]
                    
```
这个代码是ac了 但是有个地方 if j==len(s) and 0 < int(s[i:j])<=26 对这个代码我非常不满意，代码写的很不优雅，其实\
是逻辑没有梳理清楚的表现，而且这个代码只beat了 18.79%的代码，要好好研究一下别人的代码了

网上看了一个代码，运行比我的快，但是我不觉写的好

```
class Solution:
# @param s, a string
# @return an integer
    def numDecodings(self, s):
        if not s or s.startswith('0'):
            return 0
        stack = [1, 1]
        for i in range(1, len(s)):
            if s[i] == '0':
                if s[i-1] == '0' or s[i-1] > '2':  # only '10', '20' is valid
                    return 0
                stack.append(stack[-2])
            elif 9 < int(s[i-1:i+1]) < 27:         # '01 - 09' is not allowed
                stack.append(stack[-2]+stack[-1])
            else:                                  # other case '01, 09, 27'
                stack.append(stack[-1])
        return stack[-1]
```
我的代码有更好的泛化性，他的代码是规则太多了



