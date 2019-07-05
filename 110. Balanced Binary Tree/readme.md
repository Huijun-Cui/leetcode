判断是不是平衡二叉树。这个很容易吧。。。 上代码

提交一次 ac ，beat 71.12% ,但是这个代码我觉得可以更快一些，因为我们的堆栈要全部清空才能判断结果，
而我觉得没有清空堆栈前我们已经知道了结果，为社么要等到清空堆咱呢？

```
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        global flag
        flag = True
        
        def func(root):
            global flag
            if not root:
                return 0
            
            left_deepth = func(root.left)
            right_deepth = func(root.right)
            
            if abs(left_deepth - right_deepth) > 1:
                flag = False
            return max(left_deepth,right_deepth) +1
        func(root)
        
        return flag
```

我本来想自己设计一个stack 但是没有想出来，看了网友的答案，其中有一个就是我想要的效果
```
class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not root:
            return True
        def depth(node):
            if not node:    #leaves
                return 0
            left = depth(node.left) #left child's depth
            right = depth(node.right) #right child's depth
            if abs(left-right)>1:
                raise Exception #stop recursion and report unbalance
            return max(left, right)+1
        try:
            return abs(depth(root.left)-depth(root.right))<=1
        except:
            return False
```

这方法真的是太骚了哈哈哈