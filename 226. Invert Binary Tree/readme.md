
这个题有两种做法，一种是自上而下改变树的结构，第二种是自下而上改变树的结构。剑指offer里面介绍的是第一种，我们把两种方法都尝试一下

首先，自上而下

```
class Solution:
    
    def func(self,root):
        if not root:
            return 
        
        root.left,root.right = root.right,root.left
        self.func(root.left)
        self.func(root.right)
        
    
    def invertTree(self, root: TreeNode) -> TreeNode:
        self.func(root)
        
        return root
```


```
class Solution:
    
    def func(self,root):
        if not root:
            return 
        
        self.func(root.left)
        self.func(root.right)
        root.left,root.right = root.right,root.left
        
    
    def invertTree(self, root: TreeNode) -> TreeNode:
        self.func(root)
        
        return root
```













