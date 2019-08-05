这个题我用了build-in function 如下

```
from collections import deque
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.stack = deque()

    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.stack.append(x)
        

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        return self.stack.popleft()

    def peek(self) -> int:
        """
        Get the front element.
        """
        return self.stack[0]
        
        

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not len(self.stack)

```

我看了discussion  , 想起来这个题是用两个堆栈实现的，我再来实现一下，代码两次ac

```
class MyQueue:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.in_stack = []
        self.out_stack = []
        
    def push(self, x: int) -> None:
        """
        Push element x to the back of queue.
        """
        self.in_stack.append(x)

    def pop(self) -> int:
        """
        Removes the element from in front of queue and returns that element.
        """
        if not len(self.out_stack):
            while len(self.in_stack):
                self.out_stack.append(self.in_stack.pop())
        return self.out_stack.pop()
        

    def peek(self) -> int:
        """
        Get the front element.
        """
        if not len(self.out_stack):
            while len(self.in_stack):
                self.out_stack.append(self.in_stack.pop())
        return self.out_stack[-1]

    def empty(self) -> bool:
        """
        Returns whether the queue is empty.
        """
        return not len(self.out_stack) and not len(self.in_stack)
```