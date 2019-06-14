// beat 98%
class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0;
        int end = height.size()-1;
        int maxArea = 0;
        while(start<end)
        {
           if(height[start]<height[end])
           {
               if((end-start)*height[start] > maxArea) maxArea = (end-start)*height[start];
               start ++;
           }
            else
            {
                if((end-start)*height[end] > maxArea) maxArea = (end-start)*height[end];
                end--;
            }

        }
        return maxArea;
    }
};

# 这个题 我第二次做，仍然没有做出来，我原来的想法是怎么去移动两个横坐标，让他们最终停留在最大值上，然后想过快慢指针，动态规划，都没有卵用。\
这种寻找最优值的思想，可能跟平时接触深度学习有关。 
# 这个题目的主要思想，我给他起名叫探索思想吧， 就是在现在的结果上寻找比这个结果更好的方法。在已经确定的两个坐标上，移动较短的那一个，因为同样是移动，\
肯定是留住长的，让短的去探索， 也许会探索失败，成功的结果一定是基于这样的探索方法。  以下为代码：

```
class Solution:
    def maxArea(self, height: List[int]) -> int:
        start = 0
        end = len(height) - 1
        max_contain = 0
        while start != end:
            if abs(start-end) * min(height[start],height[end]) > max_contain:
                max_contain = abs(start-end) * min(height[start],height[end])
            if height[start] <= height[end]:
                start +=1
            else:
                end -=1
        return max_contain
```
