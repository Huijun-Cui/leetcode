我觉得这个是一个并查集的思想吧 最终的时间复杂度是O(n\*\*2),空间复杂度是O(n\*\*2)

代码一次ac 很爽

```
class Solution(object):
    
    def func(self,i,j):
        
        if i<0 or i >= len(self.set_id) or j<0 or j>=len(self.set_id[0]):
            return
        if self.grid[i][j] != '1':
            return
        self.set_id[i][j] = self.cur_id
        self.grid[i][j] = '2'
        
        self.func(i+1,j)
        self.func(i-1,j)
        self.func(i,j-1)
        self.func(i,j+1)
        
        
        
    
    
    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        self.grid = grid
        self.set_id = [[-1 for _ in range(len(grid[0]))] for _ in range(len(grid))]
        self.cur_id = 0
        
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if self.set_id[i][j] == -1 and self.grid[i][j] == '1':
                    self.func(i,j)
                    self.cur_id +=1
        
        return self.cur_id
```
