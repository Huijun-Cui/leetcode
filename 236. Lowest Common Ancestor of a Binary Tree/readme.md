这个题这回不是二叉搜索树，而只是二叉树

这个题我想到的是path路径对比，先遍历树得到path，时间复杂度是O(n) 然后再对比路径，时间复杂度树O（log(N)）

代码两次ac, 但是只beat了 5.03%

```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':

        ret = [None] * 2

        def func(_root, p, q, path):

            if not _root:
                return
            if _root.val == p.val:
                ret[0] = path + [_root]
            elif _root.val == q.val:
                ret[1] = path + [_root]
            
            if ret[0] and ret[1]:
                return

            func(_root.left, p, q, path + [_root])
            func(_root.right, p, q, path + [_root])

        func(root, p, q, [])

        i = 0
        
        while i < len(ret[0]) and i < len(ret[1]) and ret[0][i] == ret[1][i]:
            i +=1
        
        return ret[0][i-1]
```


网上有个代码，速度比我快了10倍，时间复杂度跟我是一样的啊。。。

```
def lowestCommonAncestor(self, root, p, q):
    stack = [root]
    parent = {root: None}
    while p not in parent or q not in parent:
        node = stack.pop()
        if node.left:
            parent[node.left] = node
            stack.append(node.left)
        if node.right:
            parent[node.right] = node
            stack.append(node.right)
    ancestors = set()
    while p:
        ancestors.add(p)
        p = parent[p]
    while q not in ancestors:
        q = parent[q]
    return q

```




