这个题要求用logn的时间复杂度 

这个题没有啥思路啊。。。。。 这个是easy题吗？

这个题感觉是是一个 因子分解的问题，看看有多少个 2 * 5，那就是先对2 因子分解之后再对5 因子分解

然后就是 min(count(2),count(5)) 就是最终的结果

开始撸代码

我最开始写的代码如下，这个代码是错误的。。。。。

```
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        count_2 = 0
        
        count_5 = 5
        
        while n % 2 ==0:
            count_2 +=1
            n = n //2
        while n % 5 == 0:
            count_5 +=1
            n = n //5
        
        return min(count_2,count_5)
```

和这个类似的题在剑指offer里面是有的，我觉得这个题应该算是中等难度题吧

这个我自己想了一下但是没有想出来啊。。。。

这个题我依然想步出来，我想不出来剑指offer里面的那个操作，。。。。

重新看下剑指offer吧 。。。

这个题最终是看了剑指offer，终于豁然开朗了，总结下这个题没能想到思路的原因

1.  这个题有经典的思路，了解这个经典思路，这个题就很简单，这也是这个题是easy的原因
2.  之前看剑指offer，稍微有点印象，但是不知道具体怎么做，这就使得想思路的时候总往剑指offer中靠，使得分析能力下降

所以基本功还是要扎实，看过的题目一定要非常懂，不然很影响解题思路

我之前的思维误区

我认为所有的数都是乘2，或者乘5得来得，所以我定义p2和p5,但是发现这样定义有问题

1 2 4 5 8 10 16 25 32  ...

可以看到8 是属于p2 下一时刻的数字是10 是5 * 2得来的，也是属于p2 那这个时候两个p2了，所以上面的定义没办法建模我们的问题。这个时候我就陷入了非常强的纠结当中，我就一直回想和推测剑指offer是怎么做的，结果都没想出来。

现在我想做的是基于分析，找到一个方法论怎么能帮我们引导到正确的解题思路。

当时我是看到了一个规律就是我们什么时候可以把一个数从队列中弹出去，就是这个数即乘以了2 也乘以了5的时候我们就可以不要这个数字了，因为我们后面再生成数肯定不是基于他生成了。

当时我就比较犯难，那我们要对数组中的每个数都要定义一个数据结构吗？ 类似于{"2_flag":bool,"5_flag":bool}

一想到要定义数据结构，我就想起来剑指offer里没有这么做，所以就不太想尝试这个方法，其实照着这个思路是可以帮我们找到正确的思路的。

    1 2 4 5 8 10

2   t t f f 

5   t f f f

如上面的表达， 我们就可以把1给排除掉了，因为他的 2 和 5 都已经成过了。 但是这样做的话，时间复杂度会很高 。

这里面进一步分析的话，我们在算4的时候需要考虑1吗？ 不需要因为 1已经乘过2了，我们只需要考虑2 


写了下面的代码，发现代码是错误的

```
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        # list(num,2 count, 5 count)
        
        data = [[1,0,0]]
        
        p2 = p5 = 0
        
        f2_count = 0
        
        f5_count = 0
        
        while True:
            
            tmp = []
            
            
            if data[p2][0] * 2 <= data[p5][0] * 5:
                tmp_num,tmp_2_c,tmp_5_c = data[p2]
                
                if tmp_num * 2 >n:
                    break
                
                tmp = [tmp_num*2,tmp_2_c+1,tmp_5_c]
                f2_count += tmp_2_c + 1
                f5_count += tmp_5_c
                
                
                
                
            else:
                tmp_num,tmp_2_c,tmp_5_c = data[p5]
                
                if tmp_num * 5 > n:
                    break
                
                tmp = [tmp_num*5,tmp_2_c,tmp_5_c+1]
                
                f2_count += tmp_2_c
                f5_count += tmp_5_c + 1
                
               
            
            data.append(tmp)
            
            while data[p2][0]*2 <= data[-1][0]:
                p2 +=1
            while data[p5][0]*5 <= data[-1][0]:
                p5 +=1
            
        
        return min(f2_count,f5_count)


Your input
15
Output
2
Expected
3
```

通过这个case发现，我们要找的数不能只包含 5和2的因子，也可以是其他因子组合，只是必须包含5或者2 ，所以以上代码是代码思想出现了错误，要重新写 。。。。。  这道easy题 我做的好辛苦啊

但是如果这样的话，我觉得要遍历一遍所有的数啊，这就是不是 log(N)的时间复杂度了。

这个题真的是难受了，后来我想道的是5的因子肯定是比2少，所以只要找出因子5的个数就可以了

```
class Solution(object):
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        count = 0
        
        while n:
            
            count +=  n //5
            
            n = n // 5
            
        return count
```







































