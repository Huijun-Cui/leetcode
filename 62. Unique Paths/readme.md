我开始是用递归做的，超时了...  通过了32个测试样例，说明程序运行结果是对的，就是超时了。。
下面的这个算法时间复杂度是 s **(M*N)  不超时才怪
```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        global count
        count = 0
        def func(i,j):
            global count
            if i == m-1 and j == n-1:
                count +=1
                return
            if i+1 < m:
                func(i+1,j)
            if j+1 < n:
                func(i,j+1)
       
        func(0,0)
        return count
```

我突然发现，这个可以是一个动态规划的问题，
f(0,0) = 1
f(m,n) = f(m,n-1) +f(m-1,n)

这里面有一个难点 比如f(m-1,n) 可能因为索引越界不存在，这个没关系，这种情况我们可以给他置0
到这，我就发现这个问题可以用O(m*n) 的时间去解决。 貌似也用不上什么 数据归纳推算，直接把数组从左到右边\
，从上到下顺序遍历就ok 了

```
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        data = [[0 for _ in range(n)] for _ in range(m)]
        data[0][0] = 1
        i, j = 0, 0

        while i < m:
            j = 0
            while j < n:
                if i == 0 and j == 0:
                    j += 1
                    continue
                left = 0
                if j - 1 >= 0:
                    left = data[i][j - 1]
                up = 0
                if i - 1 >= 0:
                    up = data[i - 1][j]
                data[i][j] = left + up
                j += 1
            i += 1
        return data[-1][-1]
```
beat 掉 78.98%的代码，成绩不是很好，我看看别人怎么写的

```
class Solution:
    # @return an integer
    def uniquePaths(self, m, n):
        aux = [[1 for x in range(n)] for x in range(m)]
        for i in range(1, m):
            for j in range(1, n):
                aux[i][j] = aux[i][j-1]+aux[i-1][j]
        return aux[-1][-1]
```
思路跟我一样啊 ，Ok...