这部分开始连续几道题都是 树的操作，我认为树的操作是比较简单的，写一写代码看看是不是真的简单
这个题目应该要求内序遍历吧 就是左中右

代码如下：

```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        global ret
        ret = []
        def func(node):
            if node == None:
                return
            func(node.left)
            ret.append(node.val)
            func(node.right)
        func(root)
        return ret
```