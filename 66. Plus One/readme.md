这个问题 比较简单了 ，不多说，直接贴代码

```
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        max_len = max(len(a),len(b))
        
        _a = a[::-1]
        _b = b[::-1]
        ret = []
        cf = 0
        i = 0
        while i < max_len:
            num_a = 0
            num_b = 0
            if i < len(a):
                num_a = int(_a[i])
            if i < len(b):
                num_b = int(_b[i])
                
            tmp_num = num_a + num_b + cf
            cf = tmp_num // 2
            tmp_num = tmp_num % 2
            ret.append(str(tmp_num))
            i+=1
        if cf:
            ret.append('1')
        return ''.join(ret[::-1])
```