这个题，看完就有思路，两次提交ac ，beat 89.45%,以下是代码,我就不明白这个题为啥会是中等难度，我觉得是easy
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        
        if head == None:
            return head
        
        new_head= ListNode(None)
        new_head.next = head
        p_f = new_head
        p_r = head
        
        pre_num = None
        
        while p_r:
            if p_r.val == pre_num:
                p_f.next = p_r.next
                p_r = p_r.next
            else:
                pre_num = p_r.val
                
                if p_r.next and p_r.val == p_r.next.val:
                    p_f.next = p_r.next
                    p_r = p_r.next
                else:
                    p_f = p_f.next
                    p_r = p_r.next
                    
        return new_head.next
```