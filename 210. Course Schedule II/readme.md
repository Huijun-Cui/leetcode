这个题跟之前的很想

```
class Solution(object):
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        from collections import defaultdict
        
        in_data = {i:set() for i  in range(numCourses)}
        out_data = defaultdict(set)
        
        for i,j in prerequisites:
            in_data[i].add(j)
            out_data[j].add(i)
        
        stack = []
        
        ret = []
        
        for item in in_data:
            if len(in_data[item]) == 0:
                stack.append(item)
                ret.append(item)
        while stack:
            
            node = stack.pop()
            
            for item in out_data[node]:
                in_data[item].remove(node)
                
                if len(in_data[item]) == 0:
                    stack.append(item)
                    ret.append(item)
            in_data.pop(node)
                    
        if len(in_data):
            return []
        
        return ret
```