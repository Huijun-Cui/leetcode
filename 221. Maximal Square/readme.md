这个题就有点难想啊。。。

这个题我想到用O(n**2)的时间复杂度做出来

代码4次提交ac，时间复杂度是O(**2) 只beat了 17.89% , 以下是我的代码
```
class Solution:
    def maximalSquare(self, matrix) -> int:
        
        if len(matrix) == 0 or len(matrix[0]) ==0:
            return 0

        from collections import defaultdict
        row = len(matrix)
        col = len(matrix[0])

        data = [[[0,0] for _ in range(col)] for _ in range(row)]
        # data element [down_most,right_most]

        max_square = -1

        for i in range(row-1, -1, -1):
            for j in range(col-1, -1, -1):

                right_most = 0
                down_most = 0
                other = 0


                if matrix[i][j] == "0":
                    continue

                if j + 1 < col:
                    if i+ 1 < row:
                        data[i][j][1] = min(data[i][j + 1][1], data[i + 1][j + 1][1]) + 1
                    else:
                        data[i][j][1] = 1
                else:
                    data[i][j][1] = 1

                if i + 1 < row:
                    if j + 1 < col:
                        data[i][j][0] = min(data[i + 1][j][0], data[i + 1][j + 1][0]) + 1
                    else:
                        data[i][j][0] = 1
                else:
                    data[i][j][0] = 1
                if min(data[i][j][0], data[i][j][1]) ** 2 > max_square:
                    max_square = min(data[i][j][0], data[i][j][1]) ** 2
        if max_square == -1:
            return 0
        return max_square
```

在网上看到一个代码，思路跟我的是一样的，但是代码比我的简练

```
class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        m = len(matrix)
        n = len(matrix[0]) if m else 0
        maxn = 0
        f = [[0] * (n+1) for _ in range(m+1)]
        for i in range(1,m+1):
            for j in range(1,n+1):
                if matrix[i-1][j-1] == '1':
                    f[i][j] = 1 + min(f[i-1][j], f[i][j-1], f[i-1][j-1])
                    maxn = max(maxn, f[i][j])
        return maxn**2
```

这个代码，找的规律真的是太牛了


