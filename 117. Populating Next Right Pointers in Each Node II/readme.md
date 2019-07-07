这个题跟116题不一样的地方是 他不是完全二叉树，这也没关系，稍微改几个代码就可以了

代码一次提交ac
```
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        queue = []
        queue.append(root)
        node_count = 1
        s_ix = 0
        while len(queue[s_ix:]):
            tmp_cout = 0
            for i in range(node_count):
                if queue[s_ix+i].left:
                    queue.append(queue[s_ix+i].left)
                    tmp_cout +=1
                if queue[s_ix+i].right:
                    queue.append(queue[s_ix+i].right)
                    tmp_cout +=1
                if i > 0:
                    queue[s_ix + i-1].next = queue[s_ix + i]
                if i == node_count -1:
                    queue[s_ix+i].next = None
            s_ix += node_count
            node_count = tmp_cout
        return root
```
代码比较简单就不多解释了