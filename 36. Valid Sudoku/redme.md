思路还是挺清晰，就是算sub matrix 坐标的时候有点懵了以下 

```
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        data_row =  [[False]*10 for i in range(9)]
        data_col =  [[False]*10 for i in range(9)]
        data_sub =  [[False]*10 for i in range(9)]
        
        for i in range(9):
            for j in range(9):
                if board[i][j]!='.':
                    tmp_data = int(board[i][j])
                    if data_row[i][tmp_data] == False:
                        data_row[i][tmp_data] = True
                    else:
                        return False
                    if data_col[j][tmp_data] == False:
                        data_col[j][tmp_data] = True
                    else:
                        return False
                    sub_ix = i//3
                    sub_jx = j //3
                    sub_merg_ix = sub_ix * 3 + sub_jx 
                    if data_sub[sub_merg_ix][tmp_data] == False:
                        data_sub[sub_merg_ix][tmp_data] = True
                    else:
                        return False
                    
        return True
                
                
```
