这个题，最直观的做法是中序遍历，放到数组中，然后取第k个，但是题中给出，如果树结构一直在变，那我们应该怎么做呢？ 

上面的这个思想太蠢了，这是一个搜索树，直接按照大于往右走，小于往左走不就行了吗？ 开始撸代码。。。

上面思想太蠢了，这个给的又不是值，而是第几个大的k,怎么走啊

我想先递归一次，给每个结点都设置一个值，表示这个树左孩子有几个，右孩子有多少个，这样我们以后查找值只需要log(n)的时间复杂度，开始撸代码。。。。

代码一次ac

以下是我的代码

```
class Solution:
    
    def get_count(self,root):
        
        if not root:
            return 0
        
        root.left_c = self.get_count(root.left)
        root.right_c = self.get_count(root.right)
        
        return root.left_c + root.right_c + 1
         
        
    
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        
        self.get_count(root)
        
        p = root
        
        while k != p.left_c + 1:
            if k > p.left_c + 1:
                k -= p.left_c + 1
                p = p.right
            
            else:
                p = p.left
        
        return p.val
```
看看其他人是怎么做的吧。。。
