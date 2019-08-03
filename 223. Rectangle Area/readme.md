这个题我想用积分的思想去做，试一试吧。。。。


这个别用积分的思想去做了，简直是作死。。。。。

最简单的方法还是分别求出两部分面积再减去他们的公共面积，这个题有一个难点就是公共面积部分怎么求？ 有没有很清晰的解体办法？ 

这个求公共部分面积的想法，我想了很久，这种问题有一个蒙蔽性就是给人感觉很好解决，但是如果要优雅地解决这个问题，并没有那么简单

我们接下来就探索这种方式


```
class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        
        area1  =  abs(C-A) * abs(D-B)
        
        area2 =  abs(G-E) * abs(H-F)
        
        left_shu = max(A,E)
        
        right_shu = min(C,G)
        
        up_heng = min(D,H)
        
        down_heng = max(B,F)
        
        width = max(0,right_shu - left_shu)
        height = max(0,up_heng - down_heng)
        
        return area1 + area2 - width*height
        
```


这个题让我想起了，当初写range 有没有交集的题，现在想想，这个题应该这么写

(s_ix1,e_ix1), (s_ix2,e_ix2)

return max(s_ix1,s_ix2) <= min(e_ix1,e_ix2)

