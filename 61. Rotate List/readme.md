这题目 思路我很早就确定了，但是提交了好多遍，shit, 然后不断debug之后才ac的，以下为代码

```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if not head:
            return None
        if k == 0:
            return head
        p_f = head
        if not p_f.next:
            return head
        p_r = p_f.next

        count = 2
        while (p_r.next):
            p_r = p_r.next
            count += 1

        step = count - k % count-1

        for _ in range(step):
            p_f = p_f.next
        if p_f.next == None:
            return head
        else:
            p_ret = p_f.next
            p_f.next = None
            p_r.next = head
            return p_ret
```

做这个题目难点在以下几点，在定义step = count - k % count-1 这个的时候总是弄混 元素个数 和 长度的概念。 还有最后一个步骤 if else的讨论，也是最后错了很多遍之后才得出的这样的写法，这个题目我做的是否分不满意

看了以下其他人的答案，思路方法跟我是一样的
```
def rotateRight(self, head, k):
    if not head or not head.next or k == 0:
        return head
    cur, l = head, 0
    while cur:
        l += 1
        cur = cur.next
    k %= l
    if k == 0:
        return head
    fast = slow = head
    for _ in xrange(k):
        fast = fast.next
    while fast and fast.next:
        fast = fast.next
        slow = slow.next
    ret = slow.next
    fast.next = head
    slow.next = None
    return ret
```