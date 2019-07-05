做这个题，我想到的方法是用函数递归的，首先左右子树都是binary search树，其次左边子树返回最大值，右边子树返回最小值，
然后判断基于当前的节点为root 是不是一个binary search树。 我们这个递归函数有两个返回值，一个是bool 型数据，另一个\
就是 返回（min or max）值。 返回min或者max值的时候还要判断他是父节点的右孩子，还是左孩子，这样递归函数还有设计一个机制\
保留父节点的信息，这样就麻烦了，不如把当前节点的最大值最小值都返回，在父节点里面进行处理。 开始撸代码

代码下出来了，写的过程非常不顺利,代码长，而且写的也费劲 ,beat 74.05%

```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def func(root):
            if root.left == None and root.right == None:
                return True,root.val,root.val
            
            left_bool,left_min,left_max = True,None,None
            
            right_bool,right_min,right_max = True,None,None
            
            cur_bool,cur_min,cur_max = True,None,None
            
            
            if root.left:
                left_bool,left_min,left_max = func(root.left)
            if root.right:
                right_bool,right_min,right_max = func(root.right)
            
            cur_bool = None
            
            if left_bool and right_bool:
                if not root.left or not root.right:
                    if not root.left:
                        if root.val < right_min:
                            cur_bool = True
                            cur_min = root.val
                            cur_max = right_max
                        else:
                            cur_bool = False
                    if not root.right:
                        if root.val > left_max:
                            cur_bool = True
                            cur_max = root.val
                            cur_min = left_min
                        else:
                            cur_bool = False
               
                elif root.left and root.right and left_max < root.val < right_min:
                    cur_bool = True
                    cur_min = left_min
                    cur_max = right_max
                else:
                    cur_bool = False
                        
            else:
                cur_bool = False
            
            return cur_bool,cur_min,cur_max
        
        if not root:
            return True
        
        ret_bool,_,_ = func(root)
        
        return ret_bool
```

从代码逻辑上能看到 一堆if else 判断，这个不是一个逻辑很好的代码,写这个程序，我对自己很不满意，主要是在\
cur_main,cur_min的时候没有想清楚，而且程序有if else 的判断，逻辑太混乱了。 

通过这个程序，我自己的总结是，写程序之前应该把所有细节都想好才可以动手写代码，不然写的时候会遇到很多麻烦。\
其实，不只是写代码， 做很多其他事情都是这个道理。有一个研究生同学，非常优秀在研究生期间发了一篇顶会，我问他秘诀的时候，\
他说在研究之前，他把问题想的很清楚，后面的工作做起来就很顺手。 我的一个初衷同学，下象棋很厉害，他也跟我说过，他下想起走一步会想很多步，想对方怎么走， 自己怎么走。   还有一个做电商很成功的朋友，他说其实创业的成功率并不低，说成功率低是因为很多人根本没有想清楚成本会有多少，预期回报是多少，因为不懂，所以估算不出来，真正投钱开始搞的时候自然失败。
我自己本身的性格是，行动容易在思想之前，这样的特点好处是执行力特别好，但是缺点是做事情考虑总是不周，如果我能够沉下心，好好考虑在先，相信做很多事情都会体验“效率”的快感 

再回过头，看看这个编程题，我已经看了别人的代码，代码很简练，我首先再捋一捋自己的思路，重新优化一下代码。 

我再回过头想这个问题的时候，我发现一个问题，如果我们用中序遍历 遍历一个binary search树的时候，一定是一个递增序列，\
如果不是递增序列。 这个是必要要条件，那我们再来考虑一下，是不是充分条件呢？ 思考了一下，也确实是充分条件，那我们就可以用\中序列遍历去遍历一个树，把得到的值存在一个gobal变量，作为 前一个值，然后每次读取节点值只要跟值比较大小就可以了。 想到\
就开始写吧 

以下是我基于这样思想写的新的版本的代码
```
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        global pre_val
        global ret_bool
        pre_val = -888888888888888888888
        ret_bool = True
        def func(root):
            global ret_bool
            global pre_val
            if not root:
                ret_bool = ret_bool and True
                return 
            
            func(root.left)
            if not ret_bool:
                return
            if root.val <= pre_val:
                ret_bool = False
                return
            else:
                pre_val = root.val
                func(root.right)
                if not ret_bool:
                    return
        func(root)
        return ret_bool
```
beat 89.80%




