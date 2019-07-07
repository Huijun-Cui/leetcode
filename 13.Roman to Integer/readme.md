我刚看到这个题，首先想到的是中序遍历，传path_list

```
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        ret = []
        def func(root,path_list,sum_num):
            if not root:
                return
            if sum_num + root.val == sum and not root.left and not root.right:
                ret.append(path_list + [root.val])
                return
            
            else:
                func(root.left,path_list + [root.val],sum_num + root.val)
                func(root.right,path_list + [root.val],sum_num + root.val)
        func(root,[],0)
        return ret
```
这个题 两次提交ac 比较简单就不多说了