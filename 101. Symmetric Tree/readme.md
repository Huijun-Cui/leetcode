这个题是判断对称，说实话，这个题我之前是做过的，如果第一次做这个题我不知道能不能相除这么优雅的解法
```
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def func(root1,root2):
            if root1 == None and root2 == None:
                return True
            
            if (root1 == None and root2 != None) or (root1!=None and root2 == None) or (root1.val != root2.val):
                return False
            
            return func(root1.left,root2.right) and func(root1.right,root2.left)
        return func(root,root)
```
代码一次ac 就不多说了