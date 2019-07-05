这个题目刚看的时候愣是没看出和108题的区别，后来才看到这里的input数据是链表，哈哈啊

这个题用最挫的方法就是O(n**2)的方法，所以我应该相出O(n)或者O(nlogn) 或者O(n)的算法

有一个方法就是 O(n) 时间复杂度把 节点都读出来，放到列表然后用108题的方法来做，时间复杂度是O(n),纳尼？\
这样真的好吗？ 但是时间复杂度确实很低啊，除非还有什么log(n)的方法

就这样，我一次ac了。。。。 beat 84.51%

```
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        nums = []
        p = head
        while p:
            nums.append(p.val)
            p = p.next
        
        def func(nums):
            if len(nums) == 0:
                return None
            
            mid_ix = (len(nums)-1) //2
            
            root = TreeNode(nums[mid_ix])
            root.left = func(nums[:mid_ix])
            root.right = func(nums[mid_ix+1:])
            return root
        
        if len(nums) == 0:
            return None
        
        return func(nums)
```

网上有个代码，看着还挺有趣
```
# recursively
def sortedListToBST(self, head):
    if not head:
        return 
    if not head.next:
        return TreeNode(head.val)
    # here we get the middle point,
    # even case, like '1234', slow points to '2',
    # '3' is root, '12' belongs to left, '4' is right
    # odd case, like '12345', slow points to '2', '12'
    # belongs to left, '3' is root, '45' belongs to right
    slow, fast = head, head.next.next
    while fast and fast.next:
        fast = fast.next.next
        slow = slow.next
    # tmp points to root
    tmp = slow.next
    # cut down the left child
    slow.next = None
    root = TreeNode(tmp.val)
    root.left = self.sortedListToBST(head)
    root.right = self.sortedListToBST(tmp.next)
    return root
```
他设置了快慢指针，让快指针每次移动 两次，慢指针每次移动一次，这样快指针到达尾部的时候，慢指针就到了中间
这种做法不行吧。。。。反正也算是一种思路吧