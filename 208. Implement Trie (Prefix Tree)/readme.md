这个是关于trie树的问题，trie树我不了解啊，我得先学一下trie树得概念

trie树的概念比较简单了，开始撸代码

代码一次ac beat 43% , 49.59%
```
class ListNode(object):
    def __init__(self,x):
        self.val = x
        self.next = {}
        self.key_flag = False

class Trie(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = ListNode(None)

    def insert(self, word):
        """
        Inserts a word into the trie.
        :type word: str
        :rtype: None
        """
        
        p = self.root
        
        for i,item in enumerate(word):
            if item not in p.next:
                p.next[item] = ListNode(item)
            p = p.next[item]
            
            if i == len(word)-1:
                p.key_flag = True
                
        

    def search(self, word):
        """
        Returns if the word is in the trie.
        :type word: str
        :rtype: bool
        """
        
        p = self.root
        
        for i,item in enumerate(word):
            
            if item not in p.next:
                return False
            
            p = p.next[item]
            
            if i == len(word)-1 and p.key_flag:
                return True
        return False
            
            
            
            
        

    def startsWith(self, prefix):
        """
        Returns if there is any word in the trie that starts with the given prefix.
        :type prefix: str
        :rtype: bool
        """
        
        p = self.root
        
        for i,item in enumerate(prefix):
            
            if item not in p.next:
                return False
            p = p.next[item]
        return True
        
```

看了一下网上写的代码，写的比我的好。。。。

```
class TrieNode:
# Initialize your data structure here.
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_word = False

class Trie:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word):
        current = self.root
        for letter in word:
            current = current.children[letter]
        current.is_word = True

    def search(self, word):
        current = self.root
        for letter in word:
            current = current.children.get(letter)
            if current is None:
                return False
        return current.is_word

    def startsWith(self, prefix):
        current = self.root
        for letter in prefix:
            current = current.children.get(letter)
            if current is None:
                return False
        return True
```