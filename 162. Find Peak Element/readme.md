
这个题我看着感觉是O（N）的时间复杂度，但是这个中等难度题啊，不能这么简单把，Long(N) 时间复杂度也不可能，

这个能加快速度的点是如果当前值比下一值大，那下一个值就不能是peak， 则ix +=2 。试一试把 

写的过程我才看到，要求用 log(N)的时间复杂度

这个题用log(n)的时间  根本没思路啊，。。。

这个题想了比较久的时间，初步掌握的规律是

我们s_ix 和 e_ix 都是定在负无穷。然后算mid ，如果mid值是一个潜在峰值，然后进行以下递归

1. 如果mid 值 比s_ix 和 e_ix 都大 那mid值就是潜在 peak s_ix 和 e_ix都向里压缩  举例减少一半
2. 如果mid 值 比 s_ix e_ix都小，那 s_ix 和 e_ix都是潜在 peak， 随便选一个  ，就选s_ix然后把 左边负无穷左边压缩
3. 如果mid ,s_ix,e_ix形成单调区间，那么也是做同样，选择最大的值作为潜在Peak然后把对应 负无穷坐标压缩

开始撸代码

写的过程遇到点问题，明天再搞吧 。。。。

写了下面的代码结果超时了 通过样例是 44/59

```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        min_num = -888888888888888888888
        data = [min_num] + nums + [min_num]
        
        s_ix = 0
        
        e_ix = len(data) -1
        
        mid = (s_ix + e_ix) // 2
        
        while True:
            
            
            
            if mid > 0 and mid < len(data) -1 and data[mid] > max(data[mid-1],data[mid+1]):
                return mid-1
            
            elif data[mid] == data[s_ix] == data[e_ix]:
                mid +=1
            
            if data[mid] >= data[s_ix] and data[mid] >= data[e_ix]:
                
                s_ix = (mid + s_ix) //2
                
                e_ix = (mid + e_ix) //2
                
                mid = (s_ix + e_ix) // 2
                
            elif data[mid] <=data[s_ix] and data[mid] <=data[e_ix]:
                
                s_ix = mid
                
                mid = e_ix
                
                e_ix = len(data)-1
                
            elif data[s_ix] <= data[mid] <= data[e_ix]:
                
                s_ix = mid
                
                mid = e_ix
                
                e_ix = len(data)-1
            
            elif data[s_ix] >= data[mid] >= data[e_ix]:
                
                e_ix = mid
                
                mid = s_ix
                
                s_ix = 0
```

后来我把代码改了一下，加了 pre_left, pre_right ,代码ac  ，但是只 beat 7.18%

```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        
        min_num = -888888888888888888888
        
        data = [min_num] + nums + [min_num]
        
        pre_left,pre_right = 0,len(data)-1
        
        s_ix = 0
        
        e_ix = len(data) -1
        
        mid = (s_ix + e_ix) // 2
        
        while True:
            
            if mid > 0 and mid < len(data) -1 and data[mid] > max(data[mid-1],data[mid+1]):
                return mid-1
            
            elif data[mid] == data[s_ix] == data[e_ix]:
                mid +=1
            
            if data[mid] >= data[s_ix] and data[mid] >= data[e_ix]:
                
                pre_left = s_ix
                
                pre_right = e_ix
                
                s_ix = (mid + s_ix) //2
                
                e_ix = (mid + e_ix) //2
                
                mid = (s_ix + e_ix) // 2
                
            elif data[mid] <=data[s_ix] and data[mid] <=data[e_ix]:
                
                s_ix = mid
                
                mid = e_ix
                
                e_ix = pre_right
                
            elif data[s_ix] <= data[mid] <= data[e_ix]:
                
                s_ix = mid
                
                mid = e_ix
                
                e_ix = pre_right
            
            elif data[s_ix] >= data[mid] >= data[e_ix]:
                
                e_ix = mid
                
                mid = s_ix
                
                s_ix = pre_left
                
```

我又写了一个O(n)的时间复杂度竟然跟我之前的 认为的Log（n） 代码速度是一样的

```
class Solution:
    def findPeakElement(self, nums: List[int]) -> int:
        
        min_num = -888888888888888
        
        data = [min_num] + nums + [min_num]
        
        i = 1
        
        while i < len(data) -1:
            if data[i] > data[i-1]:
                if data[i] > data[i+1]:
                    return i -1
                else:
                    i +=1
            else:
                if data[i] < data[i+1]:
                    i+=1
                else:
                    i +=1
```

这个就难受了