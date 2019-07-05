这个题也是做过，唉。。。。

这个题仍然是像102题那样遍历，只不过 正反交替读入就可以了

代码一次ac 就是只beat了 20.34% 难道还有更快的解法吗？ 去看一下discussion
```
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []
        cur_list = []
        next_list = []
        ret = []
        
        right_direc = 1
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
            if right_direc:
                ret.append(tmp_nums)
            else:
                ret.append(tmp_nums[::-1])
            right_direc = right_direc ^ 1
            if len(next_list) == 0:
                break
            cur_list = next_list
            next_list = []
            
        return ret
```

这种题，感觉不用纠结了 ，都是这么做的
