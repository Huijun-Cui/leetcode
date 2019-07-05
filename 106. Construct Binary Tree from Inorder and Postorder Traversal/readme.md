这个题跟105题很像啊，开始撸代码
两次提交ac
```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def func(i_nums,p_nums):
            if len(i_nums) == 0 and len(p_nums) == 0:
                return None
            if len(i_nums) == 1 and len(p_nums) == 1 and i_nums[0] == p_nums[0]:
                return TreeNode(i_nums[0])
            
            root = TreeNode(p_nums[-1])
            
            i = 0
            while i < len(i_nums):
                if i_nums[i] != p_nums[-1]:
                    i +=1
                else:
                    break
            root.left = func(i_nums[:i],p_nums[:i])
            root.right = func(i_nums[i+1:],p_nums[i:-1])
            
            return root
        if len(inorder) == 0:
            return []
        return func(inorder,postorder)
```
代码比较简单，就不想多解释了