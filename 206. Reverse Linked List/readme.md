题目中要求用递归的方式和迭代的方式去实现

迭代的方法

```
class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        p_slow = None
        p_fast = head
        
        while p_fast:
            
            tmp = p_fast.next
            p_fast.next = p_slow
            p_slow = p_fast
            p_fast = tmp
            
        return p_slow
```

递归的方法

```
class Solution(object):
    def func(self,p):

        if not p.next:
            self.ret_head = p
            return p

        self.func(p.next)

        p.next.next = p

        return p
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        if not head:
            return None
        
        self.ret_head = None
        
        self.func(head).next = None
        
        return self.ret_head
        
```

我觉得我的代码写的不够优雅，看了一下网上的代码，

迭代代码，跟我写的差不多

```
class Solution:
# @param {ListNode} head
# @return {ListNode}
def reverseList(self, head):
    prev = None
    while head:
        curr = head
        head = head.next
        curr.next = prev
        prev = curr
    return prev
```

迭代部分的代码，写的比我好太多

```
class Solution:
# @param {ListNode} head
# @return {ListNode}
def reverseList(self, head):
    return self._reverse(head)

def _reverse(self, node, prev=None):
    if not node:
        return prev
    n = node.next
    node.next = prev
    return self._reverse(n, node)
```

代码这样写之后，也就没有像我那样的全局变量了。
他的代码简便之处是 递归函数的参数是 当前结点和前一结点

而且我的代码和他的代码改变链表结构的顺序也是不一样

我的代码是一直递归到最后一个结点之后，才开始弹出栈，开始改变链表结构。 这也使得我们的函数返回值得是当前链表最开始得结点。 而他得代码是在压入栈的同时就改变了链表的结构。  这样他的返回值只需要最后一个结点就可以了，而我们是用全局变量保存的最后一个结点，使得程序不优雅。

主要还是因为我当时觉得边压入栈，边改变链表结点有顾虑。。。。。