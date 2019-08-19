提交了好多次 shit



```
class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        int l =0,r = citations.size()-1;
        while(l<r)
        {
            int mid = (l + r) >>1;
            if(citations[mid]>=citations.size() - mid) r =mid;
            else if(citations[mid] < citations.size()-mid) l = mid + 1;
        }
        if(citations[r]>=citations.size() - r) return citations.size() - r;
        else return 0;
    }
};
```