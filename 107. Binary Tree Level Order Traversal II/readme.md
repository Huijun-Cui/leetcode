这个题简单吧。。。
就是把102题 倒着输出就可以了...
一次ac beat 86.66%
```
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
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
            
        return ret[::-1]
```