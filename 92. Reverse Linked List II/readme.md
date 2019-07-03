刚开始没有想仔细，直接就写了下面代码，错了
```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        p_f_1 = ListNode(None)
        p_f_2 = head
        f_len = min(m,n) -1
        r_len = max(m,n) - 1
        for _ in range(f_len):
            p_f_1 = p_f_1.next
            p_f_2 = p_f_2.next
            
        p_r = p_f_2
        for _ in range(r_len-f_len):
            p_r = p_r.next
        
        p_f_1.next = p_r
```
改了代码之后一次ac  ,但是中间指针处理感觉好乱啊

```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        new_head = ListNode(None)
        new_head.next = head
        p_f_1 = new_head
        p_f_2 = head
        for _ in range(min(m,n)-1):
            p_f_1 = p_f_1.next
            p_f_2 = p_f_2.next
        
        p_r = p_f_2.next
        
        for _ in range(abs(m-n)):
            tmp = p_r.next
            p_r.next = p_f_2
            p_f_2 = p_r
            p_r = tmp
        
        p_f_1.next.next = p_r
        p_f_1.next = p_f_2
        
        return new_head.next
```