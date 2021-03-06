## 求子数组的最大和

前缀树

https://blog.csdn.net/Patrick\_Su/article/details/51580350 感觉for (i = n-1; i>=1; i--)判断有点问题，需要i>=0。

动态规划方法

https://blog.csdn.net/Hackbuteer1/article/details/6694193

拓展问题1：首位相接的情况。提示：采用三个变量：max，min，sum；max：最大子数组之和；min：最小子数组之和；sum：数组的总和。最后取max和sum-min的大者即为所求。

拓展问题2：有一个整数数列，其中有负数、正数，其中连续的几个数求和，求和的绝对值最大的数字串。

拓展问题3：**子数组之和的最大值（二维）**。先确定上下边界，再确定左右边界。确定上下边界的方法是枚举，确定左右边界的方法和一维问题一样。**编程之美2.15**。https://github.com/wengsht/Beauty-Of-Programming-solutions/blob/master/chapter2/2.15/source.c

拓展问题4：有一整数数列，有正负和0，其中连续几个数求和，**求和的绝对值最大的数字串**。解答：编程之美2.14扩展问题。提示：**比较最大子数组之和max与最小子数组之和min的绝对值，大的即为所求**。

拓展问题5：最大子数组的长度不可以超过n。**没找到答案**。

## 数组中重复的数字

### 剑指offer 面试题3：长度为n的的数组，所有数字都在0到n-1范围之内。输出任意一个重复的数字。

可以利用哈希表来解决问题。但这样空间复杂度为O(n)。

因为数字都在0到n-1范围内，所以如果不重复的话，其实数字该是多少就在哪个位置上。所以我们遍历数组，如果某个位置数字与index不一致，则该位置的数字与该数字应该位于的index处的数字比较，如果相同，那么找到重复数字；如果不同，那么进行交换。直到找到某个重复数字。

### 面试题3：不修改数组找出重复的数字 长度为n+1数组，数字在1到n之间，所以至少一个数字重复，找出任意一个重复数字。

可以额外开辟一个空间，然后将数字复制到额外开辟空间的指定位置上，边复制边判断。但这样需要O(n)的空间复杂度。

可以采用二分算法，将1到n的数字二分为两部分，左边为1到m，右边为m+1到n，然后统计左右存在的数字个数，即1到m有多少个数字，m+1到n有多少个数字，如果左边数字超过m，那么左边一定存在重复数字，否则右边存在重复数字。这样以此类推，不断缩小范围。（注意只需要数一边，左边或者右边的数字即可）。总的时间复杂度为O(nlgn)，但空间复杂度为O(1)，**以时间换空间的做法**。

## 二维有序数组中数据的查找，行从左往右有序，列从上到下有序。

## 数字和为sum的方法数

https://www.cnblogs.com/chongerlishan/p/6255005.html

动态规划，所给数组array，二维数组dp\[i\]\[j\]表示前i个数和为j的方法数。那么如果，j >= array\[i\]，那么dp\[i\]\[j\] = dp\[i-1\]\[j\] + dp\[i-1\]\[j-array\[i\]\]；否则，dp\[i\]\[j\] = dp\[i-1\]\[j\]。

https://www.cnblogs.com/chongerlishan/p/6255005.html

动态规划的简便，将二维数组dp变为一维数组dp\[j\]。

## 长度为n的数组，取其中k个，要求和为sum，求有多少种取法。

和数字和为sum的方法数不同，限制了取出数字的个数。

递归求法：https://blog.csdn.net/MrZZhou/article/details/77860278

## 一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。请找出这个数字

https://blog.csdn.net/sifanchao/article/details/79969016

```
find_single_number.cpp
```

首先，一个数组里面的元素可能是奇数个也可能是偶数个。同时，判断数组里的数是否成对出现有三种情况：可能有一个单数、也可能没有、还有可能有两个单数。

## 在一个数组中查找两个重复出现两次的数

https://blog.csdn.net/codeera/article/details/48861343

题目如下：现有一个数组长度为n，里面存放有1到n-2，顺序不定，其中有两个数字出现了两次，现在要找出那两个数字。例子A={2, 3, 1, 4, 5, 2, 4}，这个数组长度为7，存放了1到5，但2和4出现了两次，程序输出2和4。

方法1: 蛮力查找

时间复杂度：O(n^2)，空间复杂度O(1)。

方法2: 异或

时间复杂度O(n)，空间复杂度O(1)。

主要思想：由于限定了是1到n之间的数，且每个数至少出现一次，可以先把数组中的所有整数异或一遍，然后把结果再和1、2、3……n异或一遍，这样就得到了那两个重复出现的整数的异或结果x。

## 两个无序数组求公共交集

方法1: 使用两个for循环遍历两个数组，时间复杂度为O(n2)，空间复杂度O(1)。

方法2: 将两个数组排好序，之后设置两个数组的下标i=0，j = 0，从头到尾扫描两个数组中数是否相同，如果不同，较小的数靠后移位，**如果相同，则两个下标同时后移**，直到其中一个下标到了末尾，则结束。时间复杂度为O(nlogn)，空间复杂度O(1)。

方法3: 对长度较短的数组建立hash表，然后利用较长的数组在hash表中查找是否存在。时间复杂度为O(1)，空间复杂度O(min(N,M))。

## 两个有序数组求公共交集

上述的方法2。

## 求出一个集合的所有子集

https://blog.csdn.net/nkuhjp/article/details/52613355 递归求法

https://blog.csdn.net/yzl20092856/article/details/39995085 讲的明白，非递归算法值得参考

方法1: 通过一个整型数（int）与集合映射000...000 ~ 111...111（0表示有，1表示无，反之亦可），通过该整型数逐次增1可遍历获取所有的数，即获取集合的相应子集。**但有个缺点，集合中元素数不能大于在计算机中一个整形数的位数，一般计算机中整型数的为32位**。

```
sub_array.cpp
```

## 集合问题

### 求一个集合的所有子集问题

已知N个大于0的整数构成一个集合，即{1，2，3，……，N}，求其所有的非空且元素不相邻的子集，计算所有子集的乘积的平方的和。

https://blog.csdn.net/a568283992/article/details/53525253

### 求交集、并集、差集

利用set。set\_intersection、set\_union、set\_difference函数。

https://blog.csdn.net/zzh1301051836/article/details/48808141

## 求一个数组的最长递增子序列

https://blog.csdn.net/qq\_16836151/article/details/51244988

方法1: 转化为最长公共子序列，将原数组和排序后的原数组求最长递增子序列。

方法2: 动态规划。设数组A，L[j]表示以Aj结尾的最大子序列长度。则，L[j] = max(L[i]) + 1，where i < j && a[i] < a[j]。时间复杂度为O(n^2)。

方法3: 动态规划。O(NlogN)。

## 删除排序数组的重复项

remove\_duplication\_in\_sort\_array.cpp

## 找n个数的全排列和所有子集

https://blog.csdn.net/liyongqi\_/article/details/70472225
