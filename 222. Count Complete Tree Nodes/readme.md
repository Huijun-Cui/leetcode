这个暴力法时间复杂度应该是(2**h)

思路不太好想啊

这个题完全没思路，我觉得应该把第一个缺少 左孩子或者右孩子的结点找出来，但是这样的话时间复杂度也不低，不知道这应该怎么去解决。。。。
这个题我真的想不出来，假设树的高度是h ,那么 我们要在 h-1的告诉找出第一个出现 没有左孩子或右孩子的结点，而这个位置可以发生在h-1层的任何一个位置？  如果遍历这层的话，都要 O(2**(h-1)) ， 那跟暴力法时间复杂度一样了啊， 到这我就不知道怎么了。。。。 看答案

看了网上的答案，说实话，这个答案看完之后，我真的觉得 这个思路我想一天也想不出来，

```
def countNodes(self, root):
    if not root:
        return 0
    h1, h2 = self.height(root.left), self.height(root.right)
    if h1 > h2: # right child is full 
        return self.countNodes(root.left) +  2 ** h2 
    else: # left child is full 
        return 2 ** h1 + self.countNodes(root.right)

# the height of the left-most leaf node
def height1(self, root):
    h = 0
    while root:
        h += 1
        root = root.left
    return h
    
def height(self, root):
    if not root:
        return 0
    return self.height(root.left) + 1
```

这个思路真的是绝了，而且我觉得这种思路是基于对完全二叉树的理解。这题做不出来，我觉得我不用自责