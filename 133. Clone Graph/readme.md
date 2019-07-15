这个题刚看到之后，我觉得就按照neighbors 里面的node list 遍历下来就好了啊 。。。我再仔细想想

我觉得这个题的point是 我们根据neighbors创建一个结点，并把他指向父结点，但是这个neighbors里面的结点如果之前已经创建了，那就不需要再创建了，那我们凭借什么去判断是否已经创建了呢？ 就凭借node id ,我们凭什么来确定node id,就凭对象吧 。 我想用字典key值来存储对象，这种操作在python里面不知道是否允许，我试试吧

尝试了一下，object是可以作为字典的key值的

想到这里我才发现我刚才并没有把问题想清楚，我在这里是以原来的结点对象为键值，他的value是key的拷贝对象，我们遍历图结点，并通过字典把拷贝对象拿出来做一下 node之间的链接就可以了，这里我可能要复习一下defeault dict的用法。因为非常适合这样的场景下使用，而且我刷leetcode是希望能锻炼我的代码能力，在以后做业务的能够真的得心应手。

现在就复习一下 defeault dict的用法

网上查了，没能查到相关用法，浪费了很多时间，我自己实现这部分功能吧，再看discussion的时候看看有没有人用相关的用法

代码一次ac beat 92.39%

```
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        
        data = {}
        
        path = []
        
        def func(_node):
            path.append(_node)
            if _node not in data:
                data[_node] = Node(_node.val,[])
                
            for item in _node.neighbors:
                if item not in data:
                    data[item] = Node(item.val,[])
                data[_node].neighbors.append(data[item])
            for item in _node.neighbors:
                if item not in path:
                    func(item)
        func(node)
        
        return data[node]
                    

```

其中有一处代码写错了，找bug费了一些功夫，写成了下面这种错误的形式
```
if item not in data:
    data[item] = Node(item.val,[])
    data[_node].neighbors.append(data[item])
```

这个题，我主要时间费在了查defualt dict的用法上，我现在去discussion里看看有没有人有相关的用法

看了一下disscussion里面并没有相关的用法，倒是看到他们再用DFS和 BFS ,我再想这个跟DFS 和 BFS有什么关系吗？

看了他们的代码，我知道我这个就是BFS,

刚才说错了，我的代码是DFS,这个也是因为我对DFS 和 BFS 实操不多的原因
下面的是 BFS 和 DFS的代码
```
def cloneGraph(self, node):
    ## BFS
    dic = {}
    stack = [node] if node else []
    for i in stack:
        if i not in dic:
            dic[i] = UndirectedGraphNode(i.label)
        stack.extend([j for j in i.neighbors if j not in dic])
    for i in dic:
        for j in i.neighbors:
            dic[i].neighbors.append(dic[j])
    return dic[node] if node else node

    ## DFS
    dic = {}
    stack = [node] if node else []
    while stack:
        i = stack.pop()
        if i not in dic:
            dic[i] = UndirectedGraphNode(i.label)
        stack.extend([j for j in i.neighbors if j not in dic])
    for i in dic:
        for j in i.neighbors:
            dic[i].neighbors.append(dic[j])
    return dic[node] if node else node
```