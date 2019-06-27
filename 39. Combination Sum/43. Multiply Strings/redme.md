这个题目看着还是挺繁琐的， 我是先看了discussion ，看到里面的人是用 时间复杂度 O(n * m) 空间复杂度是 (n+m)做的，
所以我觉得不用看答案，自己也可以写，就写了下面的代码，代码效率比较低，只beat掉 10.19%的 solution,anyway 我的时间复杂度保证了就OK了

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

