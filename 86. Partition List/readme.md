这个题一次ac 思路还是蛮清晰的，不多解释了，以下代码
```
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        less_node = ListNode(None)
        p_f = less_node
        great_node = ListNode(None)
        p_r = great_node
        
        p_c = head
        
        while p_c:
            if p_c.val < x:
                p_f.next = ListNode(p_c.val)
                p_f = p_f.next
            else:
                p_r.next = ListNode(p_c.val)
                p_r = p_r.next
            p_c = p_c.next
        p_f.next = great_node.next
        
        return less_node.next
        
```