这个题，剑指offer里有，而且我还记得怎么做，直接撸代码吧 。。。。

代码三次ac

状态不好。。。

```
class Solution:
    def searchMatrix(self, matrix, target):
        
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        """
        :type matrix: List[List[int]]
        :type target: int
        :rtype: bool
        """
        i = 0
        j = len(matrix[0])-1
        
        while i <len(matrix) and j >=0:
            
            if matrix[i][j] == target:
                return True
            elif matrix[i][j]<target:
                i+=1
            else:
                j -=1
        return False
```