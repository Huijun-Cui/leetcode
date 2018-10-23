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