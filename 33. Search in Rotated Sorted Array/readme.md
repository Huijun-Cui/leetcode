这个题目，我思路还是挺确定的，但是实现出来的代码很不优雅，都是遇到错误，就进一步修改，先把代码贴出来

```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if len(nums) == 0:
            return -1
        if len(nums)==1 and nums[0] == target:
            return 0
        s = 0
        e = len(nums) - 1
        mid = (s + e ) //2
        
        while s <e:
            if nums[mid] == target:
                    return mid
            if nums[s] == target:
                return s
            if nums[e] == target:
                return e
            if nums[s] < nums[mid]:
                if nums[s] < target and target <nums[mid]:
                    e = mid
                else:
                    s = mid + 1
                mid = (s+e)//2
               
            elif nums[mid] < nums[e]:
                if nums[mid] <target and target <nums[e]:
                    s = mid+1
                else:
                    e = mid
                mid = (s+e) //2
            elif mid == s and nums[mid] !=target:
                return -1
            
            
        
        return -1
```
比如 34行这个代码是 给出错误提示之后我给改的，还有15行的20行的三个相等条件，都是报错之后加的条件，虽然这个代码AC了，但是感觉思路仍然是不清晰 。 其实编程的时候一怕没思路，\
二是怕写的时候细节处理不好，这个题目 应该好好总结一番，待续。。。。。


在 solution中看到一个 代码非常精简的代码 

```
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums) - 1
        
        while start <= end:
            
            mid = (start + end) // 2
            
            if nums[mid] == target:
                return mid
            
            if nums[mid] <= nums[end]: 
                if nums[mid] < target and nums[end] >= target:
                    start = mid + 1
                else:
                    end = mid - 1
            elif nums[start] <= nums[mid]:
                if target >= nums[start] and target < nums[mid]:
                    end = mid - 1
                else:
                    start = mid + 1
            
        return -1
```

这个代码逻辑非常清晰，在折办查找中应该遵信这种的方法


这个代码我用c++又实现了一下，主要是想练习c++同时试一下yan神的代码模板，但是很不顺利啊

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        if(nums.size() == 0) return -1;
        
        
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        
        
        
        while(l<r)
        {
            mid = (l+r)>>1;
            
            if(nums[mid] == target) return mid;
            
            if(nums[l] <= nums[mid])
            {
                if(nums[l] <= target and target<= nums[mid]) r = mid;
                else l = mid +1;
            }
            else if (nums[mid] <= nums[r])
            {
                if(nums[mid]< target and target <= nums[r]) l = mid + 1;
                else r = mid;
            }
            
            
        }
        if(nums[l] != target) return -1;
        else return l;
        
        
        
    }
    
    
};
```

在实现这个代码的时候，遇到一个问题，比如

```
[5,1]
0

```

我开始的代码没有加两个等于号，以至于代码无限循环，加了这个之后就解决了。 唉。。。。





