这个最粗暴的方式就是时间复杂度O(n)啊，还能更快吗？ 好吧，看了discussion他们是用O(1)做出来的，牛逼，我想想怎么做

这个题是什么数学规律吧，怎么完全没有头绪啊。。。

网上看了答案，这个是需要很强的分析啊

以下是代码

```
def rangeBitwiseAnd(self, m, n):
    i = 0
    while m != n:
        m >>= 1
        n >>= 1
        i += 1
    return n << i
```

