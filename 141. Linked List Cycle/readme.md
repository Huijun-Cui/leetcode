
这个是easy题，代码也是一次ac，如下

```
class Solution(object):
    def hasCycle(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        data = {}
        
        p = head
        
        while p:
            if p not in data:
                data[p] = 1
                p = p.next
            else:
                return True
        return False
```

这个题也可以用快慢指针做 ，我同样写了一个，但是也是超时，我在自己机器里跑是没问题的

```
class Solution(object):
    def detectCycle(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        p_fast = p_slow = head
        
        while True:
            
            p_slow = p_slow.next
            
            p_fast = p_fast.next
            if p_fast:
                p_fast = p_fast.next
            else:
                return -1
            
            if p_slow is p_fast:
                break
        
       
            
        search_ix = 0

        search_p = head

        while search_p is not  p_slow.next:
            search_p =  search_p.next
            search_ix +=1
        return search_ix
```