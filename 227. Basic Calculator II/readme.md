这个题，我的第一种思路是用 堆咱的想法去做的

```
class Solution:

    def get_next(self, s, ix):
        while ix < len(s) and s[ix] == " ":
            ix += 1
        
        if ix >= len(s):
            return "",ix
        
        if s[ix] in "+-*/":
            return s[ix], ix + 1

        ret_s = ""

        while ix < len(s) and s[ix] != " " and s[ix ] not in "+-*/":
            ret_s += s[ix]

            ix += 1

        return ret_s, ix

    def calculate(self, s: str) -> int:

        stack_num = []
        stack_op = []

        data = {"+": 0, "-": 0, "*": 1, "/": 1}

        num = 0

        ix = 0

        while ix < len(s):

            ret_s, ix = self.get_next(s, ix)

            if len(ret_s) and ret_s in "+-*/":
                while len(stack_op) and data[ret_s] <= data[stack_op[-1]]:
                    _op = stack_op.pop()
                    num2 = stack_num.pop()
                    num1 = stack_num.pop()
                    tmp = 0
                    if _op == "+":
                        tmp = num2 + num1
                    elif _op == "-":
                        tmp = num1 - num2
                    elif _op == "*":
                        tmp = num1 * num2
                    else:
                        tmp = num1 // num2
                    stack_num.append(tmp)
                else:
                    stack_op.append(ret_s)
                    ret_s, ix = self.get_next(s, ix)
                    if len(ret_s):
                        stack_num.append(int(ret_s))

            elif len(ret_s):
                stack_num.append(int(ret_s))



        while len(stack_op):
            _op = stack_op.pop()
            num2 = stack_num.pop()
            num1 = stack_num.pop()

            if _op == "+":
                tmp = num2 + num1
            elif _op == "-":
                tmp = num1 - num2
            elif _op == "*":
                tmp = num1 * num2
            else:
                tmp = num1 // num2
            stack_num.append(tmp)
        return stack_num[-1]
```



代码很长，我这个代码有一个问题就是用了两个堆栈，并且不是one-pass，我室友跟我说discussion里面有one-pass的思想，我后来想了想，为以下的思路

如果碰到“+-”那就不能立马算结果，还要看看下一个数字右边的数会不会是“*/”，如果是那就把算这个结果，如果不是，那就还要继续往下找 。 到这的话，貌似又是一个堆栈的问题，那么到此，我其实是没相出one-pass的算法，以下是答案

```
class Solution:
    def calculate(self,s):
        num, op, stack = 0, '+', [0]
        ops = {'+':lambda x, y: y, '-':lambda x, y: -y, '*':lambda x, y: x*y, '/':lambda x, y: (int)(float(x)/float(y))}
        for i, c in enumerate(s):
            if c.isdigit():
                num = num * 10 + int(c)
            if not c.isdigit() and c != ' ' or i == len(s)-1:
                prev = 0 if op in '+-' else stack.pop()
                stack.append(ops[op](prev, num))
                num, op = 0, c
        return sum(stack)
        
```






















