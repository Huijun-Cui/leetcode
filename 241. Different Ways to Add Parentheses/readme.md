这个题没有做过，我想一想怎么做

这个仍然是用path_list就可以做吧，不用考虑什么动态规划

我写了下面代码，没有通过

"2*-1*5"
我发现处理字符串太困难了，决定用list来处理数据

```
class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        ret = []
        op_dic = {"+":lambda x,y:x+y,"-":lambda x,y:x-y,"*":lambda x,y:x*y}
        def func(s):
            if s.isdigit() or s[1:].isdigit():
                ret.append(int(s))
            
            for i,item in enumerate(s):
                
                if item in op_dic:
                    
                    
                    s_tmp = ""
                    j = i-1
                    base = 1
                    num_left = 0
                    while j >=0 and s[j].isdigit():
                        num_left += base * int(s[j])
                        base *=10
                        j-=1
                    if j>=0 and s[j] == "-":
                        num_left *= -1
                        j -=1
                    s_tmp += s[:j+1]
                    
                    num_right = 0
                    neg_flag = False
                    j = i+1
                    if s[j] == "-":
                        neg_flag = True
                        j +=1
                    while j < len(s) and s[j].isdigit():
                        num_right = num_right * 10 + int(s[j])
                        j +=1
                    if neg_flag:
                        num_right *=-1
                    
                    s_tmp += str(op_dic[item](num_left,num_right)) + s[j:]
                    
                    
                    func(s_tmp)
        func(input)
        
        return ret
                    
```


我把代码改成如下的形式,但是对

"2 * 3 -4 * 5" 会有两个 -14的结果

比如 "6 - 4 * 5" 和  "2 * 3 - 20"

```
class Solution:

    def data_processing(self, s):
        _ret = []

        num = 0
        for i, item in enumerate(s):
            if item.isdigit():
                num = num * 10 + int(item)
            else:
                _ret.append(num)
                num = 0
                _ret.append(item)
        _ret.append(num)
        return _ret

    def diffWaysToCompute(self, input: str):

        ret = []

        s_list = self.data_processing(input)

        op_dict = {"+": lambda x, y: x + y, "-": lambda x, y: x - y, "*": lambda x, y: x * y}

        def func(s_list):

            if len(s_list) == 1:
                ret.append(s_list[0])
                return
            print(s_list)
            for i, item in enumerate(s_list):
                if item in op_dict:
                    func(s_list[:i - 1] + [op_dict[item](s_list[i - 1], s_list[i + 1])] + s_list[i + 2:])

        func(s_list)

        return ret
```

所以我的整个算法思想都出了问题

我现在想到的思路是  针对每个符号，分别递归出两个部分，开始撸代码。。。。  第三个版本了 。。。。


代码ac 了，beat 78.61% 7.14%

```
class Solution:

    def data_processing(self, s):
        _ret = []

        num = 0
        for i, item in enumerate(s):
            if item.isdigit():
                num = num * 10 + int(item)
            else:
                _ret.append(num)
                num = 0
                _ret.append(item)
        _ret.append(num)
        return _ret

    def diffWaysToCompute(self, input: str):



        s_list = self.data_processing(input)

        op_dict = {"+": lambda x, y: x + y, "-": lambda x, y: x - y, "*": lambda x, y: x * y}

        def func(s_list):

            if len(s_list) == 1:
                return s_list

            ret = []

            for i, item in enumerate(s_list):
                if item in op_dict:

                    l_ret = func(s_list[:i])
                    r_ret = func(s_list[i + 1:])

                    for l_item in l_ret:
                        for r_item in r_ret:
                            ret.append(op_dict[item](l_item, r_item))
            return ret

        return func(s_list)
```


