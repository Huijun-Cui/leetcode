感觉这个题又涉及到kmp算法了吧 ，之前有一道kmp算法题，我没有做唉。。。。

这个题我的思路就是根据wordDict里面的词把输入字符串 replace掉，然后最终判断字符串是不是为空

但是这里涉及到字符串查找的问题，要用kmp算法，所以我应该再复习一下kmp算法

之前leetcode里面的kmp算法是 28题， 

我已经把KMP算法看懂了，这两天一直在调生物钟，一道晚上7点左右就困的不行了，喝了咖啡之后瞬间满血复活。

KMP算法这次我敢说看懂了，是因为我在看算法的同时想明白了怎么用O(N)的时间构建next数组

更新next数组的代码如下：

```
def next_array(s):
    next = [0] * len(s)

    for i in range(1,len(s)):
        if s[i] == s[next[i-1]]:
            next[i] = next[i-1] +1
        else:
            next[i] = 0
    return next

def kmp(s,p,next):

    s_start = 0
    match_ix = 1
    while s_start + len(p) < len(s):
        if s[s_start] != p[0]:
            s_start +=1
            match_ix = 1
            continue

        if match_ix == len(p):
            return True

        if s[s_start+match_ix] == p[match_ix]:
            match_ix +=1
        else:
            s_start += match_ix - next[match_ix-1]
            match_ix = next[match_ix-1]
    return False

```





