这个题目，代码两次提交ac ，beat 99.76%

```
from collections import deque
class Solution(object):
    def sumNumbers(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root:
            return 0
        
        ret_num = 0
        
        de_que = deque()
        
        de_que.append((root,root.val))
        
        while len(de_que):
            
            node,num = de_que.popleft()
            
            if node.left:
                de_que.append((node.left,num * 10 + node.left.val))
            if node.right:
                de_que.append((node.right,num* 10 + node.right.val))
            if not node.left and not node.right:
                ret_num += num
        return ret_num
```
思路比较简单，就不多解释了


