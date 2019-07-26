这些都是找数学规律的题，对这种题有点怕，感觉很多问题规律不是那么容易找出来，这个题再试试

按照暴力法去解的话，时间复杂度的话没法算。可能会陷入无限循环， 所以不能用暴力法，还是要看看规则

以17为举例，这个数不是happy number，我自己手动写过程，写了几十个过程结果之后，重复出现了 25值 。 

我并不能从数学上证明所有非happy number都会出现这种 重复出现的值

搜了下discussion里关键字 O 的结果，好像没人能够在O（1）的时间复杂度做出来没说明这个没有数学公式规律在里面，而且我还看到有人用了set，那我就知道了，我上面的思路可能就是这个题的正确解法。 还有人在空间复杂度上用了O(1),这个方法我稍后再想，我先把我的算法思想实现出来

代码一次ac beat 78.85% ,虽然做出来了，但是我没法在数学公式上证明 数字会循环出现的规律

```
class Solution(object):
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """

        data = set()

        while n != 1:

            data.add(n)

            tmp = 0

            while n:
                tmp += (n%10) ** 2
                n //=10
            
            n = tmp

            if n in data:
                return False
        return True
```

现在我再想想怎么用O(1)的空间复杂度做出来

这个想法其实很简单，就是创建32（或者64位的数组），每个位置都存放

这个想法不对啊。。。   这个想法是来自于之前一道题，那个是所有数字都是重复出现，找出不重复的数啊，跟这个题是不一样的。。。

如果说我们要找出循环的数， 那还要用O(1)的空间复杂度，我不知道怎么做，看看答案把。。。

网上看了代码，他们是用了 slow fast 指针的思想， 原来这种算法有个名字叫 floyd cycle detection . 

```
    public boolean isHappy(int n) {
        // floyd cycle detection
        int slow = n;
        int fast = n;
        
        while (fast != 1) {
            slow = squaresum(slow);
            fast = squaresum(squaresum(fast));
            if (fast != 1 && slow == fast) return false;
        }
        
        return true;
    }
    
    private int squaresum(int n) {
        int ret = 0;
        while (n > 0) {
            int digit = n % 10;
            n /= 10;
            ret += Math.pow(digit, 2);
        }
        return ret;
    }
```

这种算法思想本身就是在找链表循环的位置，确实很适合这个题，good, 今天算法训练就到这。休息。。。。