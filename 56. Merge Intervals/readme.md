这个题，我的思路出现了几次偏差，写完代码才发现思路不对，因此也耗费了很多的时间，我现在把这几次偏差的代码都记录下来，\

我最开始的思路是 把orign 数据按照 每个元组元素第一个数字 从小到大排序 。 对所有数据展开排序。 这两组数据按位置比较，如果不相等，那么就是range的一个节点， I kknow it is totaly wrong !  我只是把当时stupid mistake 记录下来

```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0 or len(intervals) == 1:
            return intervals
        
        ret = []
        
        ori = [item2 for item in intervals for item2 in item]
        sort_ori = sorted(ori)
        
        start_ix = 0
        end_ix = 1
        
        while end_ix < len(ori):
            if ori[end_ix] == sort_ori[end_ix]:
                if end_ix+1 < len(sort_ori) and sort_ori[end_ix] == sort_ori[end_ix+1]:
                    end_ix +=2
                    continue
                else:
                    ret.append([sort_ori[start_ix],sort_ori[end_ix]])
                    start_ix = end_ix +1
                    end_ix = start_ix +1
            else:
                end_ix +=1
        return ret
                
```

后来我意识上面的思路不对之后，我就开始写第二个版本的代码，我想的是排序完的元祖，如果前后有重叠，那就合并，这个思路是对的，但是我的代码还是有小问题

```
Input:
[[1,4],[0,2],[3,5]]
Output:
[[0,4],[3,5]]
Expected:
[[0,5]]

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0 or len(intervals) == 1:
            return intervals
        
        ret = []
        _sort = sorted(intervals,key = lambda x:x[0])
        _sort.append([8888888888888888,888888888888888])
        
        start_ix = _sort[0][0]
        end_ix = _sort[0][1]
        
        ix = 1
        
        while ix < len(_sort):
            
            if _sort[ix][0] > end_ix:
                
                ret.append([start_ix,end_ix])
                
                start_ix = _sort[ix][0]
                
                end_ix = _sort[ix][1]
                
                ix +=1
            else:
                if _sort[ix][1] > end_ix:
                    ret.append([start_ix,_sort[ix][1]])
                    
                    if ix+1 < len(_sort):
                        start_ix = _sort[ix+1][0]
                        end_ix = _sort[ix+1][1]
                        ix+=2
                else:
                    ix += 1
       
        return ret



```


最后的版本是如下的代码

```
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0 or len(intervals) == 1:
            return intervals
        
        ret = []
        _sort = sorted(intervals,key = lambda x:x[0])
        _sort.append([8888888888888888,888888888888888])
        
        start_ix = _sort[0][0]
        end_ix = _sort[0][1]
        
        ix = 1
        
        while ix < len(_sort):
            
            if _sort[ix][0] > end_ix:
                
                ret.append([start_ix,end_ix])
                
                start_ix = _sort[ix][0]
                
                end_ix = _sort[ix][1]
                
                ix +=1
            else:
                if _sort[ix][1] > end_ix:
                    end_ix = _sort[ix][1]
                ix +=1
       
        return ret


```