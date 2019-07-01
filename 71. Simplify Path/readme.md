这个题，我觉得用o(N)时间复杂度可以做出来，就是维护一个路径列表，指定规则，然后输出就可以了

```
class Solution:
    def simplifyPath(self, path: str) -> str:
        ret = []

        i = 0
        while i < len(path):
            if path[i] == '/':
                i += 1
                continue
            tmp = []
            j = i
            while j < len(path) and path[j] != '/':
                tmp.append(path[j])
                j+=1
            tmp_str = ''.join(tmp)
            if tmp_str == '.':
                pass
            elif tmp_str == '..':
                if len(ret):
                    ret.pop()
            else:
                ret.append('/' + ''.join(tmp))

            i = j
            while i < len(path) and path[i] == '/':
                i += 1
        if len(ret):
            return ''.join(ret)
        else:
            return "/"
```

做的挺顺利，用的是O(n)的时间复杂度，但是只beat掉 32.32%,看了其他人的解决方案，用了split这样的内置函数，我虽然用\
python刷题，但我是不会用内置函数的
```
class Solution(object):
    def simplifyPath(self, path):
        s = path.split('/')
        stack = []
        for i in range(len(s)):
            if s[i] == '.' or s[i] == '':
                continue
            if s[i] == '..':
                if stack:
                    stack.pop()
            else:
                stack.append(s[i])
        return '/'+'/'.join(stack)
```