这个题是研究生考试的 机试题，当时写着感觉挺难的，现在再做一下试一试

这个代码提交三次ac,但是beat 5.02% ,what the ...

```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def func(p_nums,i_nums):
            if len(p_nums) ==0 and len(i_nums) == 0:
                return None
            
            if len(p_nums) == 1 and len(i_nums) == 1 and p_nums[0] == i_nums[0]:
                return TreeNode(p_nums[0])
            
            root = TreeNode(p_nums[0])
            
            i = 0
            while i < len(i_nums):
                if p_nums[0] == i_nums[i]:
                    break
                i +=1
            root.left = func(p_nums[1:1+i],i_nums[:i])
            root.right = func(p_nums[1+i:],i_nums[i+1:])
            
            return root
        if len(preorder) == 0:
            return []
        return func(preorder,inorder)
```

做这个题，我觉得最耗费我时间的地方是 
```
root.left = func(p_nums[1:1+i],i_nums[:i])
root.right = func(p_nums[1+i:],i_nums[i+1:])
```
这个坐标推算，总是缺少直观的解释，反而像是在蒙规律

我的总结是坐标从0开始计算，在某个地方结束，那么结束的这个坐标可以称为 偏移举例，也就是说新的坐标等于\
 new_index = start_index + offset
 所以我们用前序遍历第一个元素，在中序遍历上找到了i, 这个i就是偏移举例，那他前一个元素的偏移举例是 i-1,那在前序偏离中我们要定位的元素就是 1：1 + i -1, 我们要用在列表中的话就是1： 1 + i -1 + 1

 说到这，我就想可能这个就是为什么在计算机里起始位置都从零开始的原因，因为我们计算机的寻址都是
 段地址 + 偏移地址 ，如果我们计算机是从1开始编辑地址 那就变成 段地址 + 偏移地址 -1，每个寻址都这样多出一个-1操作，白白浪费计算机得开销啊，这个只是我个人得理解