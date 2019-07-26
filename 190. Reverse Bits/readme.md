之前做过一个题，在那个题里面 我了解到 数字在内存中是补码的形式存在的，那么我就存在一个问题啊，这个题我们要对 0，1这样bit进行移位操作，那是在补码的基础上移位吧。

补码的移位规则是 右移 补充符号位， 左移 补充0


代码两次ac

```
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        
        div_num = 2 ** 31
        
        ret_num = 0
        
        for _ in range(32):
            
            tmp_num = div_num & n
            
            if tmp_num:
                ret_num +=  2**31 / tmp_num
            
            div_num /= 2
        
        return ret_num
```
这个题有有没有数学公式转化呢？

没有啥数学公式转换，网上看了一个代码，代码写的非常漂亮， 这个代码写大好精彩啊

```
def reverseBits(self, n):
    ans = 0
    for i in xrange(32):
        ans = (ans << 1) + (n & 1)
        n >>= 1
    return ans

```

