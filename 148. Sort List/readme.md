这个要用常数的空间复杂度，就是空间复杂度为O(1)，时间要用 O(n log n)

我知道快速排序可以用 O( n log n) 那这个题该怎么做呢？ 到这里我得去复习一下快速排序得写法

复习了一下快速排序，并写了下面这个快速排序代码

```
def func(data):
    if len(data) == 0:
        return data

    left_data =[]
    right_data = []

    pivot = data[-1]

    for i in range(len(data)-1):
        if data[i] < pivot:
            left_data.append(data[i])
        else:
            right_data.append(data[i])
    left_ = func(left_data)
    right_ = func(right_data)
    return left_ +[pivot]+ right_
```

然后下面这个代码inplace quick sort

```
def func(data,s_ix,e_ix):

    if s_ix >= e_ix:
        return
    pivot = data[e_ix]
    i = s_ix
    j = e_ix

    while i != j:
        if data[i] >= pivot:
            data[i],data[j] = data[j],data[i]
            j -=1
        else:
            i +=1


    func(data,s_ix,i-1)
    func(data,i+1,e_ix)
    return
```

写上面这个代码的时候，不是很顺利，总是  上面的代码写的有bug ,改成了下面的代码

```
def func(data,s_ix,e_ix):

    if s_ix >= e_ix:
        return
    pivot = data[e_ix]
    _i = s_ix
    _j = e_ix-1
    while _i <= _j:

        if data[_i] > pivot:
            data[_i],data[_j+1] = data[_j],data[_i]
            _j -=1
        else:
            _i +=1
    data[_j+1] = pivot
    func(data,s_ix,_j)
    func(data,_j+2,e_ix)
```

我在wiki上看到的快排代码，如下这样，确实比我的代码好了很多。。。

```
import random


def swap(numbers, a, b):
    numbers[a], numbers[b] = numbers[b], numbers[a]


def partition(numbers, left, right):
    p_index = random.randint(left, right)
    p_value = numbers[p_index]

    swap(numbers, p_index, right)

    s_index = left
    for i in range(left, right):
        if numbers[i] < p_value:
            swap(numbers, i, s_index)
            s_index += 1

    swap(numbers, right, s_index)
    return s_index


def sort(numbers, left=0, right=None):
    if right is None:
        right = len(numbers) - 1

    if left >= right:
        return

    s_index = partition(numbers, left, right)

    sort(numbers, left, s_index - 1)
    sort(numbers, s_index + 1, right)


```

回到这个题，很显然不能用快速排序，可是我们知道链表的优势在于 插入高效，我们可以用 插入的方法代替 快速排序里面swap操作，，这样的时间复杂度确实是 O(n log n)


这个题我做的不是很顺利，后来写出来的还超时间了。。。 我觉得我的算法是 O（n log n），以下是我的代码,而且我真实地感觉到写代码一定要在充分休息，状态好地时候写，状态好地时候写代码效率是成倍地高。

下面地这个代码是超时了，我觉得超时的原因是 应该是 我每次选pivot都是选择头结点，但是在某些case下，这样的选择方式会让时间复杂度变成O(n**2)
```
class Solution:
    
    def _sort(self,begin_node,end_node):
        if begin_node == end_node:
            return begin_node
        
        pivot = begin_node
        
        new_head = p_left =  ListNode(-1)
        
        pre_cur = pivot
        
        cur = pivot.next
        
        while cur:
            if cur.val < pivot.val:
                p_left.next = cur
                p_left = p_left.next
                pre_cur.next = cur.next
                cur = cur.next
            else:
                pre_cur = pre_cur.next
                cur = cur.next
        p_left.next = pivot
        
        pivot.next = self._sort(pivot.next,end_node)
        
        return self._sort(new_head.next,begin_node)
        
        
    
    
    def sortList(self, head: ListNode) -> ListNode:
        
        return self._sort(head,None)
```
代码写到这，我觉得我已经尽力，既然超时，我就看看discussion

看了discussion， 他们是通过快慢指针把列表分成两份（这样就不会出现我上面提到的问题了），然后左右列表都排序好之后再给merge在一起，我只看了算法思想，实现我自己来写，希望能够一次ac bug free

代码一次ac 了  hia hia hia

```
class Solution:
    
    def merge(self,link1,link2):
        new_head =p_cur = ListNode(-1)
        while link1 and link2:
            if link1.val <= link2.val:
                p_cur.next = link1
                link1 = link1.next
                p_cur = p_cur.next
            else:
                p_cur.next = link2
                link2 = link2.next
                p_cur = p_cur.next
        if link1:
            p_cur.next = link1
        else:
            p_cur.next = link2
        
        return new_head.next
        
    
    def cut_half(self,head):
        if not head.next:
            return head
        
        slow = head
        fast = head.next
        
        while fast and fast.next:
            slow = slow.next
            fast= fast.next.next
        
        right_head = slow.next
        slow.next = None
        left = self.cut_half(head)
        right = self.cut_half(right_head)
        
        
        return self.merge(left,right)
        
    
    
    def sortList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        return self.cut_half(head)
```



