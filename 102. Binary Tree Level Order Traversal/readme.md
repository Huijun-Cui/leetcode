这个题，我也做过，我说的我做过是指以前怎么做的那种印象还留在脑海里，我尽量不去回想，而是自己找思路

两次提交ac  beat 96.20%
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        
        if not root:
            return []
        cur_list = []
        next_list = []
        ret = []
        
        cur_list.append(root)
        
        
        while True:
            i = 0
            tmp_nums = []
            while i < len(cur_list):
                tmp_nums.append(cur_list[i].val)
                if cur_list[i].left:
                    next_list.append(cur_list[i].left)
                if cur_list[i].right:
                    next_list.append(cur_list[i].right)

                i +=1
                
            ret.append(tmp_nums)
            if len(next_list) == 0:
                break
            cur_list = next_list
            next_list = []
            
        return ret
```
比较简单，就不多说了