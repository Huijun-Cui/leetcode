这个题跟62很像，提交几次出现了错误，anyway 。。。

```
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        if m == 0:
            return 0
        n = len(obstacleGrid[0])
        if n==0:
            return 0
        data = [[0 for _ in range(n)] for _ in range(m)]
        
        data[0][0] = 1
        if obstacleGrid[0][0] == 1:
            data[0][0] = 0
        if  obstacleGrid[-1][-1] == 1:
            return 0
        i, j = 0, 0

        while i < m:
            j = 0
            while j < n:
                if i == 0 and j == 0:
                    j += 1
                    continue
                left = 0
                if j - 1 >= 0:
                    if obstacleGrid[i][j-1] !=1:
                        left = data[i][j - 1]
                up = 0
                if i - 1 >= 0:
                    if obstacleGrid[i-1][j] !=1:
                        up = data[i - 1][j]
                data[i][j] = left + up
                j += 1
            i += 1
        return data[-1][-1]
```