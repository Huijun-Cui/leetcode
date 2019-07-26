代码一次ac 没啥好说的
```
class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        
        alph = 'abcdefghijklmnopqrstuvwxyz'
        
        data = {}
        
        for item in alph:
            data[item.upper()] = len(data) +1
        
        ret = 0
        
        ix = len(s)-1
        
        while ix >=0:
            
            ret += data[s[ix]] * 26 ** (len(s)-1-ix)
            
            ix -=1
            
        return ret
```