
这个题，我做过，就是用两个堆栈来搞的，争取一次ac bug free

一次ac 以下是代码

```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        stack1 = []
        stack2 = []
        
        while headA:
            stack1.append(headA)
            headA = headA.next
        while headB:
            stack2.append(headB)
            headB = headB.next
        pre_node = None
        while len(stack1) and len(stack2) and stack1[-1] is stack2[-1]:
            pre_node = stack1.pop()
            stack2.pop()
        
        return pre_node
```

可是这个题是要求空间复杂度O(1),我想了挺久没想出来。 后来我的灵感来自于以下的思想活动

比如题中给的case

4 1 8 4 5

5 0 1 8 4 5

8

我可以在上面的指针移动到1的时候，等下面的指针移动到1

想到这我明白了，我可以通过长度差，让长的先走几步然后两个指针一起移动

其实我之前的灵感思想是错误的，单是他能引导我想到正确答案

以下是我的代码，一次ac

```
class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        
        len1 = 0
        len2 = 0
        pA = headA
        
        while pA:
            len1 +=1
            pA = pA.next
        
        pB = headB
        
        while pB:
            len2 +=1
            pB = pB.next
        
        if len1 > len2:
            for i in range(len1-len2):
                headA = headA.next
        elif len2 > len1:
            for i in range(len2-len1):
                headB = headB.next
        
        while headA and headB and headA is not headB:
            headA = headA.next
            headB = headB.next
        
        return headA
```