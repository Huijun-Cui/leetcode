这个题接着118题继续做就ok 了，但是题目中给出要用 O(k) 空间复杂度，那这个题就是直接根据k来生成结果的，找规律把

想找数学规律没有找出来。。。。 其实找到数学规律了 时间复杂度是O(1),

现在我想一想可不可以用时间复杂度O（n）,而空间复杂度用O(k) ，在列表上做in place 操作完成呢？ 

发现完全可以的啊，开始撸代码

```
class Solution:
    def getRow(self, rowIndex: int) -> List[int]:
        
        ret = [0] * (rowIndex+1)
        
        ret[0] = 1
        
        for i in range(rowIndex+1):
            pre_num = 0
            for j in range(i+1):
                pre_num,ret[j] = ret[j],pre_num + ret[j]
        
        return ret
```
代码一次ac 代码比较简单就不多说了
