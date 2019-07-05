这个也是关于树的操作，剑指offer里关于这样的题非常多，这种题真的要懂套路，对递归熟悉才可以

这个问题，我初步捋出来的思路是，就是遍历所有节点，每个节点作为当前的root node,然后把所有小于这个值的节点放左子树，\
把所有大于这个数的放到右子树。这个方法我最顾虑的是效率的问题。使用的算法树广度优先遍历，在每一个层进行遍历的时候，\
要对当前层剩余的元素进行O(n)时间复杂度的遍历马？ 来确定比他小的数是哪些，比他大的数是哪些，然后分别传到当前节点的\
左，右子树中。 其实只需要O(1) 时间复杂度，因为剩余的元素是有序数列。好既然已经确定了就开始写代码。

写代码的时候发现一个问题，数据都读取完了，但是我们要把这条路径的头节点放到列表中，这个头节点我想到的就是从头传到\
尾部。 如果一个节点有分叉的时候，还要对这个节点进行复制。 现在比较没有头绪，应该怎么做。。。。 如果说通过递归，\
把path以列表的形式输出出来，这个很好办，因为path在函数中参数传递的时候，就是值传递，但是我们现在返回的指针，\
这种情况下，我们应该怎么做呢？

最粗暴的方法是，在一个节点分叉的时候，分叉几个几点，就把之前的路径复制几份。其实这种操作在广度优先遍历上是非常好操作\
的，但这个题是一个链表问题，复制问题如何解决就变的很关键

---

上面的想法真的比较糟糕，我肯定不会那么写代码，我的新的思路是，我发现当前节点要复制多少份，取决于左右子树的组合个数，\
而且这是有递归特性的，基于此思想开始撸代码

以下是我的代码，代码是一次ac了，重要的是中间的思考过程

```
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        def func(nums):
            if len(nums) == 0:
                return [None]
            
            else:
                root_list = []
                for i,item in enumerate(nums):
                    left_node = func(nums[:i])
                    right_node = func(nums[i+1:])
                    for left_item in left_node:
                        for right_item in right_node:
                            tmp_root = TreeNode(item)
                            tmp_root.left = left_item
                            tmp_root.right = right_item
                            root_list.append(tmp_root)
                
                return root_list
        if n == 0:
            return []
        return func([item+1 for item in range(n)])
```

看了一下网上的代码，思路跟我的一摸一样
```
class Solution:
    # @return a list of tree node
    # 2:30
    def generateTrees(self, n):
        nodes = map(TreeNode, range(1, n+1))
        return map(copy.deepcopy, self.buildTree(nodes))

    def buildTree(self, nodes):
        n = len(nodes)
        if n == 0:
            yield None
            return

        for i in range(n):
            root = nodes[i]
            for left in self.buildTree(nodes[:i]):
                for right in self.buildTree(nodes[i+1:]):
                    root.left, root.right = left, right
                    yield root
```