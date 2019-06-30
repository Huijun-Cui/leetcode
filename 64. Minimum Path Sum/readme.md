这个题目，我看的话仍然是一个动态规划问题，在left和up上存最大的值，然后更新当前的节点，what easy，看来还得再用以下62题得代码， let us go 


```
class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        data = [[0 for _ in range(n)] for _ in range(m)]
        data[0][0] = grid[0][0]
        i, j = 0, 0

        while i < m:
            j = 0
            while j < n:
                if i == 0 and j == 0:
                    j += 1
                    continue
                left = 8888888888888
                if j - 1 >= 0:
                    left = data[i][j - 1]
                up = 88888888888888
                if i - 1 >= 0:
                    up = data[i - 1][j]
                data[i][j] = min(left,up) + grid[i][j]
                j += 1
            i += 1
        return data[-1][-1]
```

beat 掉 84.79%得代码 not bad