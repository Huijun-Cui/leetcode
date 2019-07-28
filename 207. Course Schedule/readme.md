
这里面需要判断 不能完成课程的情况，这种情况是形成了一个 互锁 的图，判断是不是存在这样的图，我们用floyd detection

同时我们用字典来存储 node 之间的关系

我上面的想法是不对的,这个应该用出度，入度的概念去解决

代码5次提交ac ...

```
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: bool
        """
        if len(prerequisites) == 0:
            return True
        
        count = 0
        
        data = {}
        
        for val1,val2 in prerequisites:
            
            if val1 not in data:
                data[val1] = {"in":0,"out":[],"visited":False}
            data[val1]["out"].append(val2)
            
            if val2 not in data:
                data[val2] = {"in":0,"out":[],"visited":False}
            data[val2]["in"] +=1
            
        for i in range(numCourses):
            if i not in data:
                data[i] = {"in":0,"out":[],"visited":False}
                
        while count < numCourses:
            
            find_flag = False
            
            for node in data:
                
                if data[node]["in"] == 0 and not data[node]["visited"]:
                    find_flag = True
                    data[node]["visited"] = True
                    count +=1
                    for item in data[node]["out"]:
                        data[item]["in"] -=1
                    
                    break
            if not find_flag:
                return False
        
        return True
```
我这个时间复杂度是O(n**2)

看了一下discussion , 里面用了 dfs bfs ,  我想想用这两个方式怎么解决这个问题呢？ 
 
不太好想，我猜测他们的dfs bfs仍然要用出度，入度的概念，这样的话，我的代码是属于bfs方法看看他们的代码把。。

看了下网上代码，正如我之前猜想，确实用了出度入读的概念，而且我的方法就是bfs, 但是他们定义的数据结构比的简单一些
```
def canFinish1(self, numCourses, prerequisites):
    forward = {i: set() for i in xrange(numCourses)}
    backward = collections.defaultdict(set)
    for i, j in prerequisites:
        forward[i].add(j)
        backward[j].add(i)
    queue = collections.deque([node for node in forward if len(forward[node]) == 0])
    while queue:
        node = queue.popleft()
        for neigh in backward[node]:
            forward[neigh].remove(node)
            if len(forward[neigh]) == 0:
                queue.append(neigh)
        forward.pop(node)
    return not forward  # if there is cycle, forward won't be None
```

而且这个代码80ms,而我的代码是396ms， 这个差的有点多啊，我分析一下是差在哪里了 。 时间主要差在我的代码每次弹出一个结点之后，都要遍历一遍所有的结点，哪些结点的入度是0， 而网上作者这个代码是把入度为0的结点放入到队列里面，这样每次从队列中取结点，就没有查找的过程。 当时我也想做一个这样的功能了，但是嫌麻烦就没写。。。。

网上对于 bfs 是给了两个版本的代码，分别是 from the end to the front, from the front to the end

我的代码的方法是 from end to front了，因为我当时学数学结构的时候，印象中就是从出度为零来算的

当然from end to the front也可以了，以下是代码

```
def canFinish2(self, numCourses, prerequisites):
    forward = {i: set() for i in xrange(numCourses)}
    backward = collections.defaultdict(set)
    for i, j in prerequisites:
        forward[i].add(j)
        backward[j].add(i)
    queue = collections.deque([node for node in xrange(numCourses) if not backward[node]])
    count = 0
    while queue:
        node = queue.popleft()
        count += 1
        for neigh in forward[node]:
            backward[neigh].remove(node)
            if not backward[neigh]:
                queue.append(neigh)
    return count == numCourses
```

接下来我再了解一下dfs， 我猜测一下。。。。。这种方法同样要出度，入度的概念 

这个深度优先遍历，不好想啊，我印象中的深度优先遍就像中序列遍历一样。 但是这个题能用这种思想吗？  往深了遍历，不得是等他得入度为0才可以吗？ 我直接看代码吧 。。。。

```
def canFinish3(self, numCourses, prerequisites):
    forward = {i: set() for i in xrange(numCourses)}
    backward = collections.defaultdict(set)
    for i, j in prerequisites:
        forward[i].add(j)
        backward[j].add(i)
    stack = [node for node in forward if len(forward[node]) == 0]
    while stack:
        node = stack.pop()
        for neigh in backward[node]:
            forward[neigh].remove(node)
            if len(forward[neigh]) == 0:
                stack.append(neigh)
        forward.pop(node)
    return not forward
```

看了代码之后一个发现，相比于队列，这里是用里堆栈，其他地方都一样，好吧。。。 这个叫dfs 

这里回答一下我之前得疑问，即使是深度优先，也得是在入度为0得大前提下。 在这个前提下我们优先深度。因为放进stack里面都是 入度为0得点，用队列就是宽度优先，用堆栈就是深度优先