首先看到这个题，我就想用哈希方法，也就是字典，自然而然想到要排序，整个时间复杂度是 n* m * lgm beat掉90%的solution，说明方案还可以，以下是代码
```
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        data_dic = {}
        
        for i,item in enumerate(strs):
            sort_item = ''.join(sorted(item))
            if sort_item not in data_dic:
                data_dic[sort_item] = []
            data_dic[sort_item].append(item)
        
        ret = []
        for item in data_dic:
            ret.append(data_dic[item])
        return ret

```

网上差不多也是这种方法就不细看了