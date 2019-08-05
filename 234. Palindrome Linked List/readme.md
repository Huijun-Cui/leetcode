这个要求 O(n) O（1） 来做  。。。。。 唉 想想

有一种做法是先用O(n) 时间把 链表改成循环链表，然后从两头往中间走判断，。。。。 这个行吗？ 

代码两次ac

```
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        
        if not head:
            return True
        
        new_head = ListNode(None)
        
        p = new_head
        p.next = head
        q = head
        
        while q:
            
            q.pre = p
            p = p.next
            q = q.next
        
        front = new_head.next
        rear = p
        
        while front.val == rear.val and front != rear and front.next != rear:
            front = front.next
            rear = rear.pre
        
        if front.val != rear.val:
            return False
        return True
```

