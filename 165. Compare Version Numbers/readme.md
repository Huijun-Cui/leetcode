这个题我是用O(n)的时间复杂度做的，beat 56.25% ，这个题挺简单啊，为什么是中等题，难道有log n的解法吗

以下是我的代码 三次ac

```
class Solution(object):
    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        
        v1 = [int(item) for item in version1.split('.')]
        v2 = [int(item) for item in version2.split('.')]
        
        i = 0 
        
        length = min(len(v1),len(v2))
        
        while i < length:
            
            if v1[i] < v2[i]:
                return -1
            elif v1[i] > v2[i]:
                return 1
            i +=1
        
        if i == len(v1):
            j = i
            while j < len(v2):
                if v2[j] > 0:
                    return -1
                j +=1
            return 0
        else:
            j = i
            while j < len(v1):
                if v1[j] > 0:
                    return 1
                j +=1
            return 0
```