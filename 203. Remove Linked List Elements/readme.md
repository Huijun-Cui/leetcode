这个题时间复杂度肯定要O(n) 考虑有多个val值的情况 争取一次ac  bug free


一次ac

```
class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        
        new_head = ListNode(None)
        new_head.next = head
        
        p_pre = new_head
        p_rear = head
        
        while p_rear:
            if p_rear.val == val:
                p_pre.next = p_rear.next
                p_rear = p_rear.next
                continue
            else:
                p_pre = p_pre.next
                p_rear = p_rear.next
        return new_head.next
```