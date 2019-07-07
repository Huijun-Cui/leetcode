这个给出了建模，让写实现，是个easy题

三次提交ac....
```
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        if numRows == 0:
            return []
        ret = []
        ret.append([1])
        
        for i in range(1,numRows):
            tmp = []
            for j in range(i+1):
                up_num = 0 
                up_left_num = 0
                if 0<=j < len(ret[i-1]):
                    up_num = ret[i-1][j]
                if 0<=j - 1 < len(ret[i-1]):
                    up_left_num = ret[i-1][j-1]
                tmp.append(up_num + up_left_num)
            ret.append(tmp)
        return ret
```
代码比较简单就不多解释了