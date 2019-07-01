这个刚拿过来，我觉得思路还是挺清楚的，但是我看到下面有个提示说空间复杂度用O(m*n) 或者o(m+n),\
我就不是很明白，这个题既然是in place, 那还需要空间复杂度，时间复杂度O(N*m) 就完事了啊

真动手写代码的时候发现，确实最基本的方法是要 O(m*n)的空间复杂度的。 那这个问题我就着力于用O(m+n)和o(1)的\
空间复杂度去解决

最后我写的代码是O(m*n)的时间复杂度 O(1)的空间复杂度  以下是我的代码
```
class Solution:
    def setZeroes(self, matrix) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        m = len(matrix)
        n = len(matrix[0])

        i = 0
        j = 0

        while i < m:
            j = 0
            while j < n:
                if matrix[i][j] == 0:
                    for _j in range(n):
                        if matrix[i][_j] != 0:
                            matrix[i][_j] = None
                    for _i in range(m):
                        if matrix[_i][j] != 0:
                            matrix[_i][j] = None
                    matrix[i][j] = None
                j += 1
            i += 1
        i = 0
        while i < m:
            j = 0
            while j < n:
                if matrix[i][j] == None:
                    matrix[i][j] = 0
                j += 1
            i += 1
        return
```

我现在倒是好奇 O(n+m)的空间复杂度是怎么做的，同时我也好奇别人也是要遍历两遍数吗？ 看看别人怎么写吧，我看了别人的代码\
，完全没兴趣看，这个题是有solution的，solution里面O(1)空间复杂度代码 跟我写的是一样的。这里再看看O(n+m)的写法
```
class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: void Do not return anything, modify matrix in-place instead.
        """
        R = len(matrix)
        C = len(matrix[0])
        rows, cols = set(), set()

        # Essentially, we mark the rows and columns that are to be made zero
        for i in range(R):
            for j in range(C):
                if matrix[i][j] == 0:
                    rows.add(i)
                    cols.add(j)

        # Iterate over the array once again and using the rows and cols sets, update the elements
        for i in range(R):
            for j in range(C):
                if i in rows or j in cols:
                    matrix[i][j] = 0
```
以上~