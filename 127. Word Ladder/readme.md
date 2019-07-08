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

样例通过 21/40

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

