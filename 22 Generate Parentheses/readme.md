这个题目拿过来，直接想到的是遍历所有的排列情况，判断是不是有效的生成，这种复杂度太高了。然后我就想有没有动态规划的解决办法，然后我尝试把问题分解，也没找到分解办法，后来就直接看答案了，答案的实现方式如下：

```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        
        def generate(S ='',left = 0,right = 0):
            if len(S) == 2*n:
                ans.append(S)
                return
            
            if left < n:
                generate(S + '(',left + 1,right)
            if right < left:
                generate(S + ')',left,right + 1)
        generate()
        
        return ans
```

我之所以没有想到这点，没有想清楚生成合法括号对的方法， 再其次是对递归程序的生疏，写递归程序应该遵循以下三点

+ 程序的终止条件是什么
+ 由n到n+1的变化形式是什么
+ 初始条件，这个递归程序是以什么样的形式开始的