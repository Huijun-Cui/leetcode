这个问题，我看着像是求最短路径举例地问题，先用O(n* m **2)的时间复杂度勾画出 图结构，然后求最短路径距离，这个时候我要去付一下求最短路径距离的两种方法了。。。。
我看的是王道的 第五章 图论部分，我要看的是 最小生成树 Kruskal， 最短路径（两种算法） Floyd 算法和 Dijkstra 算法,我们这个算法属于  最短路径的问题，之所以要看最小生成树是因为当初这里没有学好。。。。。

# 最小生成树

### 定义

在要求解的连同图中，任意选择一些点属于集合A,剩余的点属于集合B,必定*存在*一棵最小生成树包含两个顶点分别属于集合A和集合B的边中权值最小的边。

这里面注意 是存在，而不是说所有。 我觉得他收存在的原因 可能是最小权值边不只一个的情况下吧 。这个命题是用反证法证的，证明方法很直观，就不细说了

最小生成树的构造过程，叫做Kruskal算法，如下：

+ 初始化时所有节点属于孤立的集合
+ 按照边权值递增的顺序遍历所有的边，若遍历到的边两个定点仍分属不同的集合（该边即为连通这个两个集合的边中权值最小的那条），则确定该边为最小生成树上的一条边，将这两个顶点分属的集合合并
+ 遍历完所有边后，原图中所有结点属于同一个集合则被选取的边和原图中所有结点构成最小生成树，否则原图不连通，最小生成树不存在。

# 最短路径

#### Floyd 算法

这个算法解释起来内容有点多，不写在这了，算法思想还挺直观的，时间复杂度是O(n***3)

这道题用Floyd算法写一下试试，下面是我的算法,超时间了。。。 

样例通过 21/40, 

没有通过的case  wordList 长度是599 

```
class Solution:

    def convertable(self, s1, s2):
        count = 0

        for item1, item2 in zip(s1, s2):
            if item1 != item2:
                count += 1
        return count == 1

    def ladderLength(self, beginWord: str, endWord: str, wordList) -> int:

        beginWord = beginWord + "@"
        if endWord not in wordList:
            return 0

        data_list = [beginWord] + wordList

        max_int = 8888888888888888888888
        w2i = {}
        for item in data_list:
            w2i[item] = len(w2i)
        graph = [[max_int for _ in range(len(data_list))] for _ in range(len(data_list))]

        for i in range(len(data_list)):
            for j in range(len(data_list)):
                if self.convertable(data_list[i], data_list[j]):
                    graph[i][j] = 1

        for k in range(len(data_list)):
            for i in range(len(data_list)):
                for j in range(len(data_list)):
                    if graph[i][j] > graph[i][k] + graph[k][j]:
                        graph[i][j] = graph[i][k] + graph[k][j]

        i_target = w2i[beginWord]
        j_target = w2i[endWord]

        if graph[i_target][j_target] > len(data_list):
            return 0
        return graph[i_target][j_target] + 1
```

如果Floyd算法超时那就没必要试试 Dijkstra 了，他们的时间复杂度都是一样的

这个题我实在想不出来用O(N)或者O(N**2)的时间复杂度做出来，这个也是到目前做leetcode，第一次遇到想不出思路来的时候

这个题我最后是看了答案得。。。。

答案用得是BFS算法，光BFS部分时间复杂度是O(n)，之前我没有想过BFS的时间复杂度这么低，如果之前意识到这点，我肯定会借着BFS去思考。。。。  所以各个算法的时间复杂度是多少应该有个清晰的概念，养成良好的习惯。

既然BFS的时间复杂度是O(n)，那我们应该建立一个结点之间连接的信息。我当时的想法就觉得这部分时间复杂度特别高，我们算最坏时间复杂度，每个结点都只跟一个结点相连接，连到最后一个结点，那么时间复杂度是

O(n* m + (n-1)*m  ..... + m) = O(n**2 * m)

这个时间复杂度也不低吧，假如 m == n 那这个时间复杂度也是O(n**3)了
所以这个题除非m的长度比较小，不然时间复杂度真的跟 Floyd算法是差不多的。。。

在这个问题这个题有一个非常巧妙的trick ，也正是这个trick 能让时间复杂度降低到O(n)的级别，如下：

+ Dug => \*ug
+ Dug => D\*g
+ Dug => Du*

这样的话我们借助hash map，把每个字符映射到 去词汇话（我自己起的名字）的空间中去，如下面的代码

```
all_combo_dict = defaultdict(list)
for word in wordList:
            for i in range(L):
                # Key is the generic word
                # Value is a list of words which have the same intermediate generic word.
                all_combo_dict[word[:i] + "*" + word[i+1:]].append(word)
```

这个步骤的时间复杂度是O(n*m)

这样整个时间复杂度是就是 O(n) + O (n*m)

非常巧妙的问题解法

下面是我的代码,没有AC , 这个感觉是leetcode 平台的bug ,我自己的机器，以及leetcode Testcase编译器都能顺利通过，但是一提交就出错，这。。。。怎么搞。。。

```
from collections import defaultdict
from collections import deque
de_que = deque()
class Solution:
    def ladderLength(self, beginWord, endWord, wordList):
        
        
        lexical_dict = defaultdict(list)
        
        for item in [beginWord] + wordList:
            
            for i in range(len(beginWord)):
                lexical_dict[item[:i] + "*" + item[i+1:]].append(item)
        
        
        visited_dict = defaultdict(int)
        
        
        de_que.append((beginWord,1))
        visited_dict[beginWord] = 1
        
        
        while len(de_que):
            word,level = de_que.popleft()
            
            for i in range(len(word)):
                for item in lexical_dict[word[:i] + "*"+word[i+1:]]:
                    
                    if item == endWord:
                        return level + 1
                    
                    if item != word and not visited_dict[item]:
                        de_que.append((item,level+1))
                        visited_dict[item] = 1
        return 0
```