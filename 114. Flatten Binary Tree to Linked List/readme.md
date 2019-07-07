这个题我做过，但是具体的写法我已经记不清了，我尽量按照现在的思考体系去分析这个题

这个题目说把二叉树变成一个列表，但是怎么变，他并没有将唉。。。。。题目中给出的链表顺序是中序遍历的序列，但是题目中并没有告知这样的需求啊。。。

这个题我就按照中序遍历的方法来建模把，接下来就是实现的步骤

这个程序最关键的一个实现是 返回以root为跟节点的子树，按照中序遍历顺序，返回最后一个遍历的值

做这个题，我不小心进入了一个误区，我的流程图是这么画的

```
last_val = func(root.left)
tmp = root.right
root.right = root.left
tmp.right = root.right
```
做完这个流程图之后，我就傻了吧唧去写func函数去了，func函数就是上面分析的，要返回以root为跟节点的字数，按照中序遍历返回最后一个遍历值，如下：
```
def func(root):
            if root.left == None and root.right == None:
                return root.val
            
            if not root.right:
                return func(root.left)
            else:
                return func(root.right)
        
```
然后我再回过头看这个程序的时候，递归部分不只是func ，我们把左孩子替换到右孩子的部分同样是一个自下而上的递归。。。
所以程序建模还要重新来，上面的作废 

这个程序写的过程非常不顺，首先是遇到了一个bug

我写的第一个版本的代码有bug, 在flatten代码内部定义了一个func函数，func函数参数和flattern参数同名，竟然会改变root的值，这个也是震惊了



我写了下面这个版本的程序，wrong answer 
```
class Solution:
    def func(self,root):

        if not root.left and not root.right:
            return root
        if root.left:
            pre_node = self.func(root.left)

            tmp_node = root.right

            root.right = root.left

            root.left = None
            try:
                pre_node.right = tmp_node
            except:
                print("debug")

            if tmp_node:
                return self.func(tmp_node)
            ### 这下面应该加个else 语句才可以，
            else:
                return pre_node


        elif root.right:
            return self.func(root.right)
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """

        if not root:
            return

        self.func(root)
```



下面这个程序ac了，这里面有个trick是我用了global 变量，我之前考虑用的是函数递归

```
class Solution:
    
    def func(self,root):
        global pre_node

        if not root.left and not root.right:
            pre_node = root
            return
        if root.left:
            self.func(root.left)

            tmp_node = root.right

            root.right = root.left

            root.left = None
            pre_node.right = tmp_node
            

            if tmp_node:
                self.func(tmp_node)
                return


        elif root.right:
            self.func(root.right)
            return
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        global pre_node
        pre_node = None
        if not root:
            return

        self.func(root)
```

第一个版本的代码bug修改之后，ac了

```
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        
        """
        def func(_root):

            if not _root.left and not _root.right:
                return _root
            if _root.left:
                pre_node = func(_root.left)

                tmp_node = _root.right

                _root.right = _root.left

                _root.left = None
                
                pre_node.right = tmp_node
                
                if tmp_node:
                    return func(tmp_node)
                else:
                    return pre_node


            elif _root.right:
                return func(_root.right)



        if not root:
            return

        func(root)
        
```

看一下别人是怎么写的

```
class Solution:
    # recusively
    def flatten(self, root):
        if not root:
            return 
        # flatten left child 
        self.flatten(root.left)
        # flatten right child
        self.flatten(root.right)
        # insert left child to the middle of 
        # root and right child
        tail = root.left
        if tail:
            while tail and tail.right:
                tail = tail.right
            tail.right = root.right
            root.right = root.left
            root.left = None
```
这个代码写的又简练，运行又快，差距啊

他的代码之所以这么简洁，是因为他问题建模比我清晰
他的func函数就是把当前root的sub tree张成一个链表，接下来就是链接操作，反观我的问题建模不清晰，代码难度也更大。。。。
我的问题建模是这样的
root的左边节点一定会变成他的右边节点，
左边子树最后一个节点要链接到root的右子树根节点。而这个作者建模思想是左右子树都处理好了，左子树的最后一个节点就是左边树的链表的最后一个元素，而我为了找到最后一个元素还要讨论左子树有没有右孩子。。。。唉。。。。
做这个题，一定要把问题清晰分解，写代码会事半功倍










