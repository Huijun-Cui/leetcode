这个题刚看到，input 数据看着蒙蔽，放在json viewer 上才看明白数据结构。。。 坑。。。

这个题完全可以按照程序遍历来做，但是题中给了这个是完全二叉树这个信息，那想想有没有更高效的方法，层序遍历时间复杂度是O(2n),而空间复杂度是O(2n), 我觉得这个效率可以了啊，还能有log(n)的时间复杂度吗？ 我们用层序遍历是要2 pass, 我觉得借助完全二叉树的信息，我们应该相出one pass的方法

这个思路就对了，第一层取1，第二层取2 ，第三层取4， 好开始写代码，因为python里面没有双向队列，我们就不弹出队首元素，而是用快慢指针来表示

代码三次提交ac
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
            for i in range(node_count):
                if queue[s_ix+i].left:
                    queue.append(queue[s_ix+i].left)
                    queue.append(queue[s_ix+i].right)
                if i > 0:
                    queue[s_ix + i-1].next = queue[s_ix + i]
                if i == node_count -1:
                    queue[s_ix+i].next = None
            s_ix += node_count
            node_count *=2
        return root
        
```
代码比较简单，不多解释了