## 史上最全最丰富的“最长公共子序列”、“最长公共子串”问题的解法与思路

https://blog.csdn.net/wangdd\_199326/article/details/76464333

## 最长公共子序列（求最长公共子序列长度并统计最长公共子序列的个数）

重点不止求最长公共子序列长度，还要统计最长公共子序列的个数。

https://www.cnblogs.com/huashanqingzhu/p/7435750.html

https://blog.csdn.net/moep0/article/details/52760974

https://blog.csdn.net/litble/article/details/67640655

```
g[2][maxn] 统计子序列个数
g[cur][j] = 0;

if(f[cur][j] == f[cur^1][j]) g[cur][j] += g[cur^1][j];  
if(f[cur][j] == f[cur][j-1]) g[cur][j] += g[cur][j-1];  
if(f[cur][j] == f[cur^1][j] && f[cur][j] == f[cur][j-1] && f[cur^1][j-1] == f[cur][j]) 
	g[cur][j] -= g[cur^1][j-1];
if(A[i] == B[j] && f[cur][j] == f[cur^1][j-1] + 1) g[cur][j] += g[cur^1][j-1]; 
```

## 求解两个字符串的最长公共子序列

动态规划（最优子结构+重叠子问题）

https://www.cnblogs.com/hapjin/p/5572483.html

## 求两个字符串的最长公共子串

动态规划，和上述问题类似。只是在字符串str1的位置i和字符串str2的位置j的字符不相同的情况下，处理方式不一样。

https://blog.csdn.net/x\_i\_y\_u\_e/article/details/52537688

## 求多个字符串的最长公共子串

广义后缀树（Generalized Suffix Tree，简称GST）算法。

https://blog.csdn.net/nomad2/article/details/6404196

## 求重复出现过的最长子串：单字符串问题，分为可重叠重复子串和不可重叠重复子串

后缀树

https://blog.csdn.net/jinzhao1993/article/details/52966761

链接：https://www.nowcoder.com/questionTerminal/859d3e13ebb24e73861e03141bbe9cfb?source=relative
来源：牛客网

这样的时间复杂度为：生成后缀数组 O(N)、排序O(NlogN\*N)最后面的N是因为字符串比较也是O(N)、依次检测相邻的两个字符串O(N * N)。总的时间复杂度是O(N^2\*logN)。

## 求最长不重复子串：单字符串问题

从一个字符串中找到一个连续子串，该子串中任何两个字符不能相同，求子串的最大长度并输出一条最长不重复子串。

http://dsqiu.iteye.com/blog/1701324

https://www.cnblogs.com/leavescy/p/5877109.html

### 使用Hash

要求子串中的字符不能重复，判重问题首先想到的就是hash。

### 动态规划

动态规划思想就是用于处理有重叠问题的求解，最大不重复子串一定是两个相同字符夹着的一段字符串加上这个字符，如abcac这里的最大不重复子串是a夹的一段。

### 动态规划+Hash求解

```
map<char, int>
```

遍历字符串，对每个字符做以下操作：

* 如果当前字符出现过并且该字符上一次出现时的index大于目前子串的初始index，那么将目前子串的初始index置为该字符上一次出现时的index。注意这个子串不一定是最大长度的子串，而是程序运行过程中当前的不重复子串。**同时也封信map该key对应的value**。
* 如果当前的index与startIndex（目前子串的初始index）的差值大于maxLen（记录的最长不重复子串的长度），那么更新maxLen。注意，因为我们要输出这个不重复子串，所以我们在这时候（maxLen改变时）需要记录startIndex。
* 记录当前字符的index。

## 可以输入多组字符串，输入a-z代表0-25，例如.输入ab，输出1. ab=0\*26^1+1\*26^0

字符串解析 编程

https://blog.csdn.net/qingcunsuiyue/article/details/69218715

```
str1.cpp
```
