
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

网上看了几个 log n 的代码，跑了之后发现，他们跑出来的速度跟我一样。。。。


这个代码跟我的代码的思想是一样的，但是为什么他的代码能如此简炼？

他的问题建模比我的简单，就是不断调整mid 让他往高处走

他的比较方式也是骚， 只跟mid + 1 比比较，就凭这个比较就能找到峰值。。。



```
class Solution:
    def findPeakElement(self, nums):
        if not nums:
            return 0
        l, r = 0, len(nums)-1
        while l <= r:
            if l == r:
                return l
            mid = l + (r-l)//2
            # due to "mid" is always the left one if the length of the list is even,
            # so "mid+1" is always valid.
            if (mid-1 < 0 or nums[mid-1] < nums[mid]) and nums[mid] > nums[mid+1]:
                return mid
            elif nums[mid] > nums[mid+1]:
                r = mid
            else:
                l = mid + 1
```

下面这个代码很神奇啊，这个能找到峰值吗？ my god....

这个代码的思想 就是r 坐标定位在比右边值大的地方， l坐标定位比左边值小的地方。

这里有个问题就是 r l 之间有没有可能没有 极大值，只有极小值。 答案是不可能，因为我们开始的两个端点都是 无穷小的值，

然后这里为什么只跟 mid + 1 比较呢？ 因为如果mid 刚好落在那么 他的左右两边都存在极大值，任意一个返回值都可以，所以这里固定地向由移动

下面这个也是相同地思想
```
def findPeakElement2(self, nums):
    l, r = 0, len(nums)-1
    while l < r:
        mid = l + (r-l)//2
        if nums[mid] > nums[mid+1]:
            r = mid
        else:
            l = mid + 1
    return l 
    
```