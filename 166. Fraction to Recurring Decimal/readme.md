这个题的关键点在于怎么判断是不是无限循环数

只要判断当前余数和前一时刻余数相等那就无限循环数，此时把一直到前一时刻的余数连接起来就可以了

代码两次提交， 超时间了，以下是代码

```
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        
        shang = numerator // denominator
        
        yu = numerator % denominator
        
        ret_yu = []
        
        flag = False
        
        while yu:
            
            ret_yu.append(str(yu*10//denominator))
            _yu = yu* 10 % denominator
            
            if _yu == yu:
                flag = True
                break
            yu = _yu
        if len(ret_yu) and flag:
            return str(shang) + "." + '('+''.join(ret_yu) + ')'
        elif len(ret_yu):
            return str(shang) + "." +''.join(ret_yu) 
        else:
            return str(shang)

4
333
```
4 / 333 == 0.0120120120.....

难怪会超时

那该如何判断是不是无限循环小数呢？ 

那就从分解因子的角度去考虑这个问题

下面代码ac

```
class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        
        neg_flag = False
        
        if numerator * denominator < 0:
            neg_flag = True
        
        numerator = abs(numerator)
        
        denominator = abs(denominator)
        
        shang = numerator // denominator
        
        yu = numerator % denominator
        
        ret_yu = []
        
        set_yu = [yu]
        
        
        
        flag = False
        
        recur_ix = None
        
        while yu:
            
            _yu = yu* 10 % denominator
            
            ret_yu.append(str(yu*10//denominator))
            
            if _yu in set_yu:
                flag = True
                recur_ix = set_yu.index(_yu)
                break
            else:
                set_yu.append(_yu)
                
                yu = _yu
        
        ret_str = ""
        
        if neg_flag:
            ret_str = "-"
        
        if len(ret_yu) and flag:
            ret_str += str(shang) + "." + ''.join(ret_yu[:recur_ix])+ '('+''.join(ret_yu[recur_ix:]) + ')'
        elif len(ret_yu):
            ret_str += str(shang) + "." +''.join(ret_yu) 
        else:
            ret_str += str(shang)
        
        return ret_str

```
