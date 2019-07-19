这个题我想到的是用 队列 和 栈来做，如下 ,结果时间又超时了，我自己机器跑是没问题的啊，今天真是醉了

```
class Solution:
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        from collections import deque

        d_queue = deque()
        stack = []
        p = head

        while p:
            d_queue.append(p)
            stack.append(p)
            p = p.next

        length = len(stack)

        new_p = new_head = ListNode(-1)

        while length:

            new_p.next = d_queue.popleft()

            new_p = new_p.next

            length -= 1

            if length:
                new_p.next = stack.pop()
                new_p = new_p.next
                length -= 1
        return new_head.next
```