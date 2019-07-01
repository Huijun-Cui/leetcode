这个题我 我觉得思路还是挺清晰的，先找target number属于哪个row 然后用binary search就可以了，\
时间复杂度是O(n),以下是代码 
```
class Solution:
    def searchMatrix(self, matrix, target: int) -> bool:
        if len(matrix) == 0:
            return False
        if len(matrix[0]) == 0:
            return False
        for i, row in enumerate(matrix):
            if row[-1] >= target:
                if row[0] > target:
                    return False
                left = 0
                right = len(matrix[0]) - 1
                mid = (left + right) // 2
                while left < right:
                    if row[mid] == target:
                        return True
                    if row[mid] < target:
                        left = mid + 1
                    else:
                        right = mid - 1
                    mid = (left + right) // 2

                if row[mid] == target:
                    return True
                return False

        return False

```