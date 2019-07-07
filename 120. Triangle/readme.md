这道题要求用 O（n） 空间复杂度，完全没问题啊
第一次提交的代码的代码有bug， 写之前没有想清楚

```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n_rows = len(triangle)
        path_sum = [888888888888888888] * len(triangle)
        path_sum[0] = 0
        for i in range(n_rows):
            for j in range(i+1):
                up_left,up,up_right = 888888888888888888888,path_sum[j],888888888888888888
                if j>0:
                    up_left = path_sum[j-1]
                if j < len(path_sum)-1:
                    up_right = path_sum[j+1]
                path_sum[j] = min(up_left,up,up_right) + triangle[i][j]
        
        return min(path_sum)
```

这个代码的错误在于 比如读第二性[3,4]的时候，读3的时候会改变path_sum的值，而这个改变了的值会影响读入4的结果

同时上上面代码有个bug 是不应该有 up_right的判断


发现这个bug之后，我想可能要pre_path 和cur_path，这个仍然是O(n)的时间复杂度啊，行就照这个搞吧



```
class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        
        max_int = 8888888888888888
        
        path_sum = [0] * len(triangle)
        
        path_sum[0] = triangle[0][0]
        
        for i in range(1,len(triangle)):
            
            cur_sum = [0] * len(triangle)
            
            for j in range(i+1):
                up_left = max_int
                up = max_int
                
                if j > 0:
                    up_left = path_sum[j-1]
                
                if j < len(triangle[i-1]):
                    up = path_sum[j]
                cur_sum[j] = min(up_left,up) + triangle[i][j]
            path_sum = cur_sum
        
        return min(path_sum)
```

我想看看别人的代码是不是也用了O(2n)的空间复杂度，我看到下面的代码，代码很古怪，运行速度和空间占用都不如我的代码，关键是这个思路很不好想
```
class Solution:
    def minimumTotal(self, triangle):
        if not triangle:
            return 
        res = triangle[-1]
        for i in range(len(triangle)-2, -1, -1):
            for j in range(len(triangle[i])):
                res[j] = min(res[j], res[j+1]) + triangle[i][j]
        return res[0]
```
其实这个代码的思路还是遵循 一个最短路径 他的子路径一定也是最短路径这样的思路