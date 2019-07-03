这个题找规律，花了比较多的时间，我最开始想的是 怎么用one-hot编码 xor 操作得到结果，然后去寻找one-hot编码变化的,\
规律，然后我在n==3的情况 结果写出来的时候发现了 另一个规律，我发现序列呈现都是 2**(n-1)  + 前面的数据列，而且\

然后我开始动手写程序的时候又发现 以最高位分界点，可以发现，最高位以为的后面的序列是镜像对称的。

```
class Solution:
    def grayCode(self, n: int) -> List[int]:
        if n == 0:
            return [0]
        pre_node = [0,1]
        
        i = 2
        
        while i <=n:
            tmp = []
            tmp.extend(pre_node)
            base = 2 ** (i-1)
            for item in pre_node[::-1]:
                tmp.append(item + base)
            pre_node = tmp
            i +=1
        return pre_node

```

一次就ac  beat 97.59%
看了别人写的代码，也都是这种思路，我这个代码已经很简练了，就不贴别人的代码了