to be honest , 我真的不喜欢这种类型的题，题目一拿过来，我就不想做，真的做起来，也是经过很繁琐的细节，找到数字变换的数学规律，提交了两次，是wrong answer之后再重新找数学规律 ，我的时间复杂度是O(n)

```
class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        
        
        if len(matrix) == 0:
            return []
        count = 0
        row = len(matrix)
        col = len(matrix[0])
        
        ret = []
        
        while count < 0.5 * row and count < 0.5 * col:
            j = count
            if count > col -1 -count:
                count +=1
                continue
            
            while j <= col - 1 - count:
                ret.append(matrix[count][j])
                j +=1
            i = count + 1
            if count + 1 > row - 1 - count:
                count +=1
                continue
            while i <= row-1-count:
                ret.append(matrix[i][col-1-count])
                i +=1
            j = col-2-count
            if col-2-count < count:
                count +=1
                continue
            while j >= count:
                ret.append(matrix[row-1-count][j])
                j -=1
            
            i = row - 2 - count
            if row-2-count < count + 1:
                count +=1
                continue
            while i >= count+1:
                ret.append(matrix[i][count])
                i -=1
            count +=1
        return ret
```