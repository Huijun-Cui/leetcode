这个代码我两次提交就过了，主要是因为跟前面33题很像 ，出现过的错误是while 里面 if elif 这部分写错成 if if 了
```
class Solution:
    def Left(self, nums: List[int], target: int) -> List[int]:
        s = 0
        e = len(nums)-1
        mid = (s+e) //2
        
        while s<=e:
            if nums[mid] == target:
                if mid != 0 and (nums[mid] == nums[mid-1]):
                    e = mid - 1
                else:
                    return mid
            elif nums[mid] < target:
                s = mid+1
            else:
                e = mid - 1
            mid = (s + e) //2
        return -1
    
        
    def Right(self, nums: List[int], target: int) -> List[int]:
        s = 0
        e = len(nums)-1
        mid = (s+e) //2

        while s<=e:
            if nums[mid] == target:
                if mid !=len(nums)-1 and (nums[mid] == nums[mid+1]):
                    s = mid + 1
                else:
                    return mid
            elif nums[mid] < target:
                s = mid+1
            else:
                e = mid - 1
            mid = (s + e) //2
        return -1
        
        
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        result = []
        result.append(self.Left(nums,target))
        result.append(self.Right(nums,target))
        return result
```