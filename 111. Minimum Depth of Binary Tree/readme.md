这个题，我首先想到的是层序遍历，

提交一次ac
```
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        nums = []
        tmp_store = []
        depth = 0
        
        if not root:
            return 0
        nums.append(root)
        continue_flag = True
        while continue_flag:
            depth +=1
            for item in nums:
                if not item.left and not item.right:
                    continue_flag = False
                    continue
                if item.left:
                    tmp_store.append(item.left)
                if item.right:
                    tmp_store.append(item.right)
            nums = tmp_store
            tmp_store = []
        return depth
```