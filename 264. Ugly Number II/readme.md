剑指offer里面的原题，但是我开始的时候没有vector数组，刚开始先错了，觉得没必要开数组。
```
class Solution {
public:
    int Min(int x,int y,int z)
    {
        int min_ret = (x<y)?x:y;
        min_ret = (min_ret<z)?min_ret:z;
        return min_ret;
    }
    int nthUglyNumber(int n) {
        vector<int> data = {1};
        int p_2 = 0,p_3 = 0,p_5 = 0;
        
        while(data.size() < n)
        {
            auto min_next = Min(data[p_2] * 2,data[p_3]*3,data[p_5]*5);
            data.push_back(min_next);
            while(data[p_2] * 2 <=min_next) p_2++;
            while(data[p_3] * 3 <=min_next) p_3++;
            while(data[p_5] * 5 <=min_next) p_5++;
            
        }
        return data[n-1];
        
        
    }
};
```
