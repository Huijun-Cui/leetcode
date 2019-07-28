之前做过trie树，可以用trie树的方法， 毕竟trie树的优点是空间换时间，但是这还要支持正则表达，这个就优点麻烦唉，那就相当于要把trie树 某一层的所有结点都遍历啊

如果用字典来存储呢？ 

这个时候可以算一算时间复杂度很高，又两种方法 addWord的时候处理，和search的时候处理，前者的时间复杂度是2 ** n,后者的时间复杂度是26**n

如果用trie树的话，时复杂度依然是怎么高

还有一种思路是 同样是用trie树，但是使用正序tire树和倒序trie树，两个树同时遍历这样就能大大增加时间效率
本来26\*\*m的时间复杂度就变成了  26\*\*(m/2) ,我觉得这个就是最快的方法了吧，开始撸代码

代码撸完之后发现思路是错误的。。。。 这个有点难受了。。。


假如下面的例子：


word = "abcd"
dict_word = "abxxxxxxxcd"

word会匹配成功，但是这种匹配是错误的。。。。。


```
from collections import defaultdict
class ListNode(object):
    def __init__(self):
        self.next = defaultdict(ListNode)
        self.is_word = False


class WordDictionary(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.f_root = ListNode()
        self.b_root = ListNode()

    def addWord(self, word):
        """
        Adds a word into the data structure.
        :type word: str
        :rtype: None
        """
        cur_f = self.f_root
        cur_b = self.b_root
        for i,item in enumerate(word):
            cur_f = cur_f.next[item]
            cur_b = cur_b.next[word[len(word)-1-i]]
                
    def func_match(self,word,cur_node,ix):
        if ix >len(word)//2+1 or ix > len(word)-1:
            return True
        
        flag = False
        if word[ix] == '.':
            for item in cur_node.next:
                flag |= self.func_match(word,cur_node.next[item],ix+1)
        elif word[ix] not in cur_node.next:
            flag = False
        else:
            flag |= self.func_match(word,cur_node.next[word[ix]],ix+1)
        
        return flag
            
           
        
    def search(self, word):
        """
        Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter.
        :type word: str
        :rtype: bool
        """
        
        return self.func_match(word,self.f_root,0) and self.func_match(word[::-1],self.b_root,0)
```


我后来想了一下，我没必要用两颗trie树搞，因为边的数量是题目中给的，不会大到26\*\*m个

那接下来我们就用一个trie树搞。

