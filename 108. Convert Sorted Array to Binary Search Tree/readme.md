这个是要生成二叉平衡树，这个不太好想啊，这个是easy题？

我想到的方法是 每次从有序数组的中间位置取数字

一次ac beat 90.37% 以下是代码
```
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> TreeNode:
        def func(nums):
            if len(nums) == 0:
                return None
            
            mid_ix = (len(nums)-1) //2
            
            root = TreeNode(nums[mid_ix])
            root.left = func(nums[:mid_ix])
            root.right = func(nums[mid_ix+1:])
            return root
        
        if len(nums) == 0:
            return None
        
        return func(nums)
```