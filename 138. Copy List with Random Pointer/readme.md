这个题 我觉得很简单啊，就是沿着next移动，把当前结点拷贝一份，拷贝的结点设置next和random就Ok了啊，我觉得这个题时间复杂度是O(N) ，而且是 one pass ， 开始撸代码

两次ac

```
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        
        data = {}
        
        p = head
        if not head:
            return None
        while p:
            if p not in data:
                data[p] = Node(p.val,None,None)
                
            if p.next:
                if p.next not in data:
                    data[p.next] = Node(p.next.val,None,None)
                data[p].next = data[p.next]
            
            if p.random:
                if p.random not in data:
                    data[p.random] = Node(p.random.val,None,None)
            
                data[p].random = data[p.random]
            
            p = p.next
        return data[head]
```