class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        cf = 0
        while l1.next != None and l2.next != None:
            cf = int((l1.val+l2.val + cf)/10)
            returnNode = (l1.val + l2.val + cf) % 10
            l1 = l1.next
            l2 = l2.next
        if l1.next !=None
