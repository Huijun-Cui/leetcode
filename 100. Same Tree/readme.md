判断两颗儿叉树相同，我记得有一个理论就是，前序和后序可以唯一确定一颗树，所以对这个问题，可以用前序和后序\
分别对两棵树进行遍历，如果序列都相同那就唯一确定，但是时间复杂度是比较高的，我们要想出更高效的方法。

我的想法是，一个递归函数分别接收两个树的指针，然后同步同方向移动指针，如果相同那就是相同的两颗树，可是听着怎么好像在说中序列遍历可以唯一确定一棵树啊，我再来看看  我思考验证了一下，跟那种 中序遍历是不是唯一确定一棵树是两回事，开始撸代码

之前做98题，我写了长长的心得，做这个题我就借鉴98题时的心得，这个题两次提交ac了，beat 90.53%

```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        def func(p,q):
            
            if p==None and q==None:
                return True
            
            if (p==None and q !=None) or (q==None and p!= None )  or p.val != q.val:
                return False
            
            return func(p.left,q.left) and func(p.right,q.right)
        
        return func(p,q)
            
```