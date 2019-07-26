这个数难点在于 next() 时间复杂度要求O(1) hasNext() 时间复杂度要求 O(h)

以下是我的代码

```
class BSTIterator(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        
        p = root
        if p:
            while True:
                self.stack.append(p)
                if not p.left:
                    break
                p = p.left
        self.pre_node = p
        self.pop_flag = False
        

    def next(self):
        """
        @return the next smallest number
        :rtype: int
        """
        
        self.pre_node = cur = self.stack.pop()
        self.pop_flag = True
        
       
        return cur.val
            
        
        
        

    def hasNext(self):
        """
        @return whether we have a next smallest number
        :rtype: bool
        """
         
        if self.pre_node and self.pop_flag:
            p_right = self.pre_node.right
            if p_right:
                self.stack.append(p_right)

                p_right = p_right.left

                while p_right:
                    self.stack.append(p_right)
                    p_right = p_right.left
        self.pop_flag = False
        
        
        
        return len(self.stack)
```