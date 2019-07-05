代码比较简单，三次提交ac beat 83.62%

```
class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        def func(sum_num,root):
            if not root:
                return False
            
            if sum_num + root.val == sum and (not root.left) and not (root.right):
                return True
            
            return func(sum_num+root.val,root.left) or func(sum_num+root.val,root.right)
        sum_num = 0
        return func(sum_num,root)
            
```