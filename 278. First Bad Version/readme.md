下面是ac代码，但是我用了强制类型转换。

```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1,r = n;
        while(l<r)
        {
            long long mid = l+r>>1;
            if(isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return (int)r;
    }
};
```

不用强制转换符，就用以下的代码
我之前代码是写错了写成了 int mid = l + (r-l)>>1;
```
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1,r = n;
        while(l<r)
        {
            int mid = l+ (r-l)/2;
            if(isBadVersion(mid)) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};
```
我