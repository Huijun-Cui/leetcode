这个题一次ac,easy题就不多解释了
```

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        new_head = ListNode(None)
        new_head.next = head
        p_f = new_head
        p_r = head
        
        while p_r:
            if p_r.val == p_f.val:
                p_f.next = p_r.next
                p_r = p_r.next
            else:
                p_f = p_f.next
                p_r = p_r.next
        return new_head.next
```