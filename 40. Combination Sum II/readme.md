因为有前面39题的基础，这个题目代码很快就写出来了，但是有两点上代码不是很清晰，先贴山代码
```
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        def func(candidates,target,ix,path_list,ret,pre_ix):
            
            if target == 0:
                ret.append(path_list)
                return
            
            for ix2 in range(pre_ix+1,len(candidates)):
                if ix2 > pre_ix + 1 and candidates[ix2] == candidates[ix2-1]:
                    continue
                if target < candidates[ix2]:
                    return
                else:
                    func(candidates,target-candidates[ix2],ix2,path_list + [candidates[ix2]],ret,ix2)
        ix = 0
        path_list = []
        ret = []
        func(candidates,target,ix,path_list,ret,-1)
        
        return ret
```
1.pre_ix 初始值设定 -1 这个是偶然发现的，其实逻辑上设置-1 没什么意义，在这个题上感觉是个凑巧
2. 最初的代码会有bug ,比如在[10,2,1,2,7,6,1,5] 这个代码里，会出现两次 1 2 5 这种输出，我后来想到这个代码既然是广度优先遍历，我在同一个层中 不要让它们跟前一个节点相同就可以解决这个问题 
