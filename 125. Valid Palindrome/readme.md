这个题，挺简单，但是平台貌似有bug啊，以下是我地代码
```
class Solution(object):
      def isPalindrome(self, s):
            
            word_list = "abcdefghijklmnopqrstuvwxyz"

            i = 0
            j = len(s) -1

            while i < j:
                if s[i].lower() not in word_list:
                    i +=1
                    continue
                if s[j].lower() not in word_list:
                    j -=1
                    continue
                if s[i].lower() != s[j].lower():
                    break
                else:
                    i+=1
                    j-=1
            if i < j:
                return False
            else:
                return True
```