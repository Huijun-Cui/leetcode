按照我的理解，这种题没有动态规划算法， 能把递归函数写出来就ok....


代码一次ac ，beat 100% ...  要这么夸张吗？ 

```
class Solution:       
        
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        
        ret = []
        
        def func(path,target,ix):
            
            if target < 0:
                return

            if len(path) == k:
                if target == 0:
                    ret.append(path)
                return

            for i in range(ix,10):

                func(path + [i],target-i,i+1)
        func([],n,1)
        return ret
```