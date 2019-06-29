又是这种螺旋神马遍历，因为之前做过类似题，把数学变化规律找出来，写出来就ok了

```
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        
        fill_num = 1
        ret = [[0 for i in range(n)] for j in range(n)]
        
        count = 0
        
        while 0.5 * n > count:
            
            if count > n-1-count:
                count +=1
                continue
            i = j = count
            while j <= n-1-count:
                ret[i][j] = fill_num
                fill_num +=1
                j +=1
            
            if count+1 > n-1-count:
                count +=1
                continue
            j = n-1-count
            i = count + 1
            while i <= n-1-count:
                ret[i][j] = fill_num
                fill_num +=1
                i +=1
            if n-2-count < count:
                count +=1
                continue
            i = n-1-count
            j = n-2-count
            while j >= count:
                ret[i][j] = fill_num
                fill_num +=1
                j -=1
            if n-2-count < count + 1:
                count +=1
                continue
            j = count
            i = n-2-count
            while i >= count +1:
                ret[i][j] = fill_num
                fill_num +=1
                i -=1
            count +=1
        return ret
```