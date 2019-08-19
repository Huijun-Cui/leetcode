
beat 100% 我就不看别的solution了
```
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]>=citations.size()-i) return citations.size()-i;
        }
        return 0;
        
    }
    
    
};
```