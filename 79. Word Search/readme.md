真的是蛋疼，这恶题我在剑指offer上做过，把那个方法搬过来用竟然又超时间了，以下是代码，通过的测试样例85/87
代码应该没问题，就是超时
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        path = [[False for _ in range(len(board[0]))] for _ in range(len(board))]
        
        def func(i,j,_str,path):
            if len(_str) == 0:
                return True
            
            if board[i][j] != _str[0]:
                return False
            if board[i][j] == _str[0] and len(_str) == 1:
                return True
            
            path[i][j] = True
            left = False
            right = False
            up = False
            down = False
            
            if j>0 and path[i][j-1] == False:
                left = func(i,j-1,_str[1:],path)
            
            if j < len(path[0])-1 and path[i][j+1] == False:
                right = func(i,j+1,_str[1:],path)
            
            if i >0 and path[i-1][j] == False:
                up = func(i-1,j,_str[1:],path)
                
            if i < len(path)-1 and path[i+1][j] == False:
                down = func(i+1,j,_str[1:],path)
            
            path[i][j] = False
            
            return left or right or up or down
        
        for i,row in enumerate(board):
            for j,col in enumerate(row):
                if func(i,j,word,path):
                    return True
        return False
```

那既然超时，我就觉得可能是因为函数递归的原因，我避免用函数递归，但是仍然用 相同的时间复杂度试一试

我看了以下别人写的代码，也是用递归，但没有超时

```
class Solution(object):
    def exist(self, board, word):
        if not board:
            return False
        for i in xrange(len(board)):
            for j in xrange(len(board[0])):
                if self.dfs(board, i, j, word):
                    return True
        return False

    # check whether can find word, start at (i,j) position    
    def dfs(self, board, i, j, word):
        if len(word) == 0: # all the characters are checked
            return True
        if i<0 or i>=len(board) or j<0 or j>=len(board[0]) or word[0]!=board[i][j]:
            return False
        tmp = board[i][j]  # first character is found, check the remaining part
        board[i][j] = "#"  # avoid visit agian 
        # check whether can find "word" along one direction
        res = self.dfs(board, i+1, j, word[1:]) or self.dfs(board, i-1, j, word[1:]) \
        or self.dfs(board, i, j+1, word[1:]) or self.dfs(board, i, j-1, word[1:])
        board[i][j] = tmp
        return res
```

这个代码跟我的代码思路是一样的啊，也是用函数递归，但是为什么他的就不超时？  研究一下  不管了，这个代码再请教一下别人把。。。。

仔细对比了，我和他的代码，发现有不一样的地方，我用了path, 他没有用，确实可以不用path,我再想难道是因为path的原因，
造成我的程序超时吗？ 是因为path太大，程序内存开销大，导致程序跑的慢？ 好像不是啊，电脑并没有卡顿的现象，我验证一下

我把代码改成下面的形式仍然超时，
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        
        def func(i,j,_str):
            if len(_str) == 0:
                return True
            
            if board[i][j] != _str[0]:
                return False
            if board[i][j] == _str[0] and len(_str) == 1:
                return True
            
            tmp = board[i][j]
            board[i][j] = "#"
            left = False
            right = False
            up = False
            down = False
            
            if j>0 and board[i][j-1] != "#":
                left = func(i,j-1,_str[1:])
            
            if j < len(board[0])-1 and board[i][j+1] != "#":
                right = func(i,j+1,_str[1:])
            
            if i >0 and board[i-1][j] != "#":
                up = func(i-1,j,_str[1:])
                
            if i < len(board)-1 and board[i+1][j] !="#":
                down = func(i+1,j,_str[1:])
            
            board[i][j] = tmp
            
            return left or right or up or down
        
        for i,row in enumerate(board):
            for j,col in enumerate(row):
                if func(i,j,word):
                    return True
        return False
```

显然不是什么path问题，那是什么问题呢？ 我把代码在进一步修改成如下，已经非常趋近于网上的代码了，还是超时
```
class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        
        
        def func(i,j,_str):
            if len(_str) == 0:
                return True
            
            if i<0 or i>=len(board) or j < 0 or j>=len(board[0]) or board[i][j] != _str[0]:
                return False
            
            if board[i][j] == _str[0] and len(_str) == 1:
                return True
            
            tmp = board[i][j]
            board[i][j] = "#"
            left = False
            right = False
            up = False
            down = False
            
            left = func(i,j-1,_str[1:])
            
            
            right = func(i,j+1,_str[1:])
            
           
            up = func(i-1,j,_str[1:])
                
            
            down = func(i+1,j,_str[1:])
            
            board[i][j] = tmp
            
            return left or right or up or down
        
        for i,row in enumerate(board):
            for j,col in enumerate(row):
                if func(i,j,word):
                    return True
        return False
```
