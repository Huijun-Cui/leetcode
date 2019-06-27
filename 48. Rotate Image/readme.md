这个题就是找坐标转换规律，我是用O(n) 时间做出来的

```
class Solution:
    def rotate(self, matrix) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """

        def convert_ix(i, j, n):
            return j, n - i - 1

        count = 0
        s_i = 0
        _s_j = 0
        n = len(matrix)

        while n > 0:
            for col_ix in range(n-1):
                s_j = _s_j + col_ix
                tmp_data = matrix[s_i][s_j]
                for _ in range(4):

                    s_i, s_j = convert_ix(s_i, s_j,len(matrix))
                    tmp_data, matrix[s_i][s_j] = matrix[s_i][s_j], tmp_data
            n -= 2
            s_i = 0
            _s_j = 0
            count += 1
            s_i += count
            _s_j += count
```

这个问题网上有很多精简的代码，但是我觉得都是找数学规律，我就不再看了