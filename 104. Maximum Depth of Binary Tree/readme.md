这个题非常简单了吧，。。。。。

三行代码，一次ac
```
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root == None:
            return 0
        
        return max(self.maxDepth(root.left),self.maxDepth(root.right)) + 1
```