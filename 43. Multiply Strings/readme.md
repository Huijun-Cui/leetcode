这个程序，我先是看了discussion里面 看到时间复杂度是O(n*m) 空间复杂度是 o(n+ m ) 就自己写了 

```
class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        
        if int(num1) == 0 or int(num2) == 0:
            return '0'
        pre_result = [0] * len(num1)
        cur_result = []

        for i1, item1 in enumerate(num1[::-1]):
            cur_result = [0] * i1
            mul_cf = 0
            for i2, item2 in enumerate(num2[::-1]):
                tmp_num = int(item1) * int(item2) + mul_cf
                mul_cf = tmp_num // 10
                tmp_num = tmp_num % 10
                cur_result.append(tmp_num)
            cur_result.append(mul_cf)

            add_cf = 0
            ix_add = 0
            while ix_add < len(cur_result):
                if ix_add >= len(pre_result):
                    break
                tmp_num = cur_result[ix_add] + pre_result[ix_add] + add_cf
                add_cf = tmp_num // 10
                tmp_num = tmp_num % 10
                pre_result[ix_add] = tmp_num
                ix_add += 1

            if ix_add >= len(pre_result):
                while ix_add < len(cur_result):
                    tmp_num = cur_result[ix_add] + add_cf
                    add_cf = tmp_num // 10
                    pre_result.append(tmp_num)
                    ix_add +=1
            else:
                while ix_add < len(pre_result):
                    tmp_num = pre_result[ix_add] + add_cf
                    add_cf = tmp_num // 10
                    ix_add += 1
        ret_str =  ''.join([str(item) for item in pre_result])[::-1]
        ix_start = 0
        while ix_start < len(ret_str):
            if ret_str[ix_start] == '0':
                ix_start +=1
            else:
                break
        return ret_str[ix_start:]
```

代码很长，我看了网友是怎么写的其中一个代码写的很精简，但是不符合题目规范，但仍然可以说是好代码

```
class Solution(object):
    def multiply(self, num1, num2):
        """
        :type num1: str
        :type num2: str
        :rtype: str
        """
        l1 = map(int, num1)[::-1]
        l2 = map(int, num2)[::-1]
        sum = 0
        for i, m in enumerate(l1):
            for j, n in enumerate(l2):
                sum += m * n * 10 ** (i + j)
        return str(sum)
```

以下的代码是 这个问题最好的解决方法了 

```
class Solution(object):
    def multiply(self, num1, num2):
        num1, num2, l1, l2, carry, start = num1[::-1], num2[::-1], len(num1), len(num2), 0, 0
        ans = [ 0 for i in xrange(l1 + l2) ]
        for i in xrange(len(num1)):
            for j in xrange(len(num2)):
                ans[i + j] += int(num1[i]) * int(num2[j])
        for i in xrange(len(ans)):
            ans[i], carry = (ans[i] + carry ) % 10, (ans[i] + carry) / 10
        ans = map(str, ans)
        answer = ''.join(ans)[::-1]
        while start < len(answer) and answer[start] == '0':
            start += 1
        return answer[start:] if start != len(answer) else '0'
```

这个程序最经典的地方是，发现了这种问题的本质规律  ans[i + j] += int(num1[i]) * int(num2[j])  ，这种形式我觉得更像是一种套路把， 算法复杂度一样，但是这种实现方式代码更简练