刚开始理解错了提议，我以为T 字符串里面的词都是unique呢，所以写了以下的代码

```
class Solution {
public:
    string minWindow(string s, string t) {
        
        if(s.size() == 0) return "";
        map<char,int> hash;
        for(int i=0;i<t.size();i++) hash[t[i]] = 0;
        
        int cur_len = INT_MAX;
        int sum = 0;
        int p_slow = 0,p_fast = 0;
        string ret = "";

        while(p_fast <=s.size())
        {
            if(sum >= t.size()) 
            {
                if(p_fast - p_slow< cur_len)
                {
                    cur_len = p_fast - p_slow;
                    ret = s.substr(p_slow,p_fast - p_slow);
                }
                if(hash.find(s[p_slow]) !=hash.end())
                {
                    hash[s[p_slow]]--;
                    if(hash[s[p_slow]] == 0) sum--;
                    
                }
                p_slow ++;
            }
            else
            {
                if(hash.find(s[p_fast]) != hash.end())
                {
                    if(hash[s[p_fast]] == 0)  sum++;
                    hash[s[p_fast]]++;
                }
                p_fast ++;
            }
        }
        return ret;
    }
};
```

其实这个代码还有一处没有解决好的地方是 if(sum >= t.size())

以下是AC代码

```
class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> hash;
        
        for(int i=0;i<t.size();i++) hash[t[i]] ++;
        
        unordered_map<char,int> data;
        
        int i = 0;
        int sum = 0;
        for(;i<s.size() && sum < hash.size();i++)
        {
            if(hash.count(s[i]))
            {
                data[s[i]]++;
                if(data[s[i]] == hash[s[i]]) sum++;
            }
        }
        if(sum < hash.size()) return "";
        
        int p_slow = 0,p_fast = i-1;
        string ret = s.substr(p_slow,p_fast - p_slow + 1);
        while(p_fast < s.size())
        {
            if(p_fast - p_slow + 1 < ret.size()) ret = s.substr(p_slow,p_fast - p_slow + 1);
            if(hash.count(s[p_slow])) data[s[p_slow]]--;
            while(hash.count(s[p_slow]) && data[s[p_slow]] < hash[s[p_slow]] && p_fast < s.size()) 
            {
                p_fast ++;
                if(hash.count(s[p_fast])) data[s[p_fast]] ++;
            }
            p_slow ++;
        }
              
        return ret;
        
    }
};
```