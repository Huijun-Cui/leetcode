这个题不就是装换成进制的问题吧。 这里是26进制，这种问题都是不断除26，取出商进行一下步迭代，开始撸代码吧

写代码的时候遇到一个问题，比如52 ： 表达方式是AZ ,因为这里没有表达0的字母

所以我们每次取模 如果是0，那就要商数减一，这个位置写Z

代码ac

```
class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        
        data = ['None','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']
        
        ret = []
        
        while n>26:
            
            shang = n // 26
            
            mo = n % 26
            
            if mo == 0:
                shang -=1
                mo = 26
            
            ret.append(data[mo].upper())
            
            n = shang
            
        ret.append(data[n].upper())
        
        return ''.join(ret[::-1])
```