代码一次ac


```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        
        while max(p.val,q.val) < root.val or root.val < min(p.val,q.val):
            
            if max(p.val,q.val) < root.val:
                
                root = root.left
            else:
                root = root.right
            
        
        return root
```