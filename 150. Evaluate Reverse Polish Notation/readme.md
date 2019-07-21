这个题我觉得就是栈的应用吧，碰到数字就压入，碰到符号就弹出，这个题怎么能算中等题呢？ 

代码两次提交ac

```
class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        
        for item in tokens:
            if item in ["+","-","*","/"]:
                num1 = stack.pop()
                num2 = stack.pop()
                
                if item == "+":
                    stack.append(num1 + num2)
                elif item == "-":
                    stack.append(num2-num1)
                elif item == "*":
                    stack.append(num1 * num2)
                elif item == "/":
                    tmp = abs(num2) // abs(num1)
                    if num2 * num1 < 0:
                        tmp = -tmp
                    stack.append(tmp)
            else:
                stack.append(int(item))
        return stack[0]
```