这个题是一个循环递归问题，开始撸代码

这个题做的不是很顺利，联系三个wrong answer之后，我发现的逻辑是错误的。。。 这个太尴尬了。。。以下是我的代码
```
class Solution(object):

    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        if len(board) == 0:
            return []
        global visited
        visited = [[0 for _ in range(len(board[0]))] for _ in range(len(board))]

        def func(board, i, j):

            visited[i][j] = 1
            left, right, up, down = False, False, False, False

            if board[i][j] == "X":
                return True
            if i < 0 or i >= len(board) or j < 0 or j >= len(board[0]):
                return False
            if j - 1 >= 0:
                if visited[i][j - 1] == 0:
                    if board[i][j - 1] == "X":
                        left = True
                    else:
                        left = func(board, i, j - 1)
                else:
                    left = True
            if not left:
                visited[i][j] = 0
                return False
            if j + 1 < len(board[0]):
                if visited[i][j + 1] == 0:
                    if board[i][j + 1] == "X":
                        right = True
                    else:
                        right = func(board, i, j + 1)
                else:
                    right = True
            if not right:
                visited[i][j] = 0
                return False
            if i - 1 >= 0:
                if visited[i - 1][j] == 0:
                    if board[i - 1][j] == "X":
                        up = True
                    elif board[i - 1][j] == "O":
                        up = func(board, i - 1, j)
                else:
                    up = True
            if not up:
                visited[i][j] = 0
                return False
            if i + 1 < len(board):
                if visited[i + 1][j] == 0:
                    if board[i + 1][j] == "X":
                        down = True
                    elif board[i + 1][j] == "O":
                        down = func(board, i + 1, j)
                else:
                    down = True
            if not down:
                visited[i][j] = 0
                return False
            visited[i][j] = 0
            board[i][j] = "X"
            return True


        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "O":
                    func(board, i, j)
```

代码长又出错，我是在下面这个case里发现我的代码逻辑错误的

```
[["O","O","O","O","X","X"],["O","O","O","O","O","O"],["O","X","O","X","O","O"],["O","X","O","O","X","O"],["O","X","O","X","O","O"],["O","X","O","O","O","O"]]
```

我现在新的思路，我发现不能fill x的case是 这个O 是在矩阵的边缘。那我们把 和矩阵边缘的O连接的所有O找出来就可以了，时间复杂度是O(n**2)


这个程序很好写，但是中间 我把if not visit 写成if not not visit ，debug了好半天才发现这个错误。

还有刚开始我没加上 else: return 这么个句子，使得程序无限循环

```
class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        
        if len(board) == 0:
            return []
        
        visited = [[0 for _ in range(len(board[0]))] for _ in range(len(board))]
        
        def func(board,i,j):
            if board[i][j] == "O":
                board[i][j] = "R"
                visited[i][j] = 1
            else:
                return
            
            if i -1 >=0:
                if not visited[i-1][j]:
                    func(board,i-1,j)
            if i + 1 < len(board):
                if not visited[i+1][j]:
                    func(board,i+1,j)
            if j-1 >=0:
                if not visited[i][j-1]:
                    func(board,i,j-1)
            if j+1 < len(board[0]):
                if not visited[i][j+1]:
                    func(board,i,j+1)
            return 
        
        
        for i in range(len(board)):
            if board[i][0] == "O":
                func(board,i,0)
            if board[i][len(board[0])-1] == "O":
                func(board,i,len(board[0])-1)
        for j in range(len(board[0])):
            if board[0][j] == "O":
                func(board,0,j)
            if board[len(board)-1][j] == "O":
                func(board,len(board)-1,j)
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == "R":
                    board[i][j] = "O"
                else:
                    board[i][j] = "X"
```

别人的代码慢慢再看吧 今天累了

看到一个这个代码，代码速度比我的慢，但是我们的时间复杂度是一样的

```
def solve(self, board):
    if not any(board): return

    m, n = len(board), len(board[0])
    save = [ij for k in range(m+n) for ij in ((0, k), (m-1, k), (k, 0), (k, n-1))]
    while save:
        i, j = save.pop()
        if 0 <= i < m and 0 <= j < n and board[i][j] == 'O':
            board[i][j] = 'S'
            save += (i, j-1), (i, j+1), (i-1, j), (i+1, j)

    board[:] = [['XO'[c == 'S'] for c in row] for row in board]
```

这个代码 save = [ij for k in range(m+n) for ij in ((0, k), (m-1, k), (k, 0), (k, n-1))] 不容易懂，写的不好，下面也有人提出 为什么不把range(m+n) 改为 max(m,n) 

还有这个代码 'XO'[c=='S'] 写的很骚，作者是深得pytyhon代码得精髓啊，，，， 这个代码思路是跟我想得一一样得，我是用了函数递归，他是用了一个堆。 我得函数比多用了一个visited 矩阵，其实这个是不需要得因为board里面元素改成了“R”就已经说明访问过了。