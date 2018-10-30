/*
算法题：数组划分为和最相近2个子数组
*/

/*
https://blog.csdn.net/junbujianwpl/article/details/80220308?utm_source=blogxgwz0
双指针法
*/

vector<vector<int> > Leetcode::partitionNearestSumSubArr(const vector<int> &arr)
{
    if(arr.size()<2){
        return vector<vector<int> >({arr,vector<int>()});
    }

    vector<int> sortedArr=arr;
    SortAlgorithmn::quickSort(sortedArr);//排序

    int sum=0;
    for(const auto& i : sortedArr) sum+=i;

    auto lClose=sortedArr.begin();//左闭右开
    auto rOpen=sortedArr.begin()+1;

    auto minDist=std::numeric_limits<int>::max();
    int curSum=*sortedArr.begin();
    for(auto i=sortedArr.begin(),j=sortedArr.begin()+1;i<j && j<=sortedArr.end();){
        int curDist=curSum*2-sum;
        if(abs(curDist)<minDist){
            lClose=i;
            rOpen=j;
            minDist=abs(curDist);
            if(minDist == 0) break;
        }
        if(curDist>0){
            curSum-=(*i);
            ++i;
        }else if(curDist<0){
            curSum+=(*j);
            ++j;
        }else{
            lClose=i;
            rOpen=j;
            break;
        }
    }

    vector<int> first;
    first.assign(lClose,rOpen);
    sortedArr.erase(lClose,rOpen);;

    return vector<vector<int> >({first,sortedArr});
}

/*
https://blog.csdn.net/pegasuswang_/article/details/25081783
dfs和dp方法
*/

/*dfs*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 20 + 5;
const int INF = 0x3f3f3f3f;
int n, ans, sum;
int w[M];
void dfs(int i, int cursum) {
    if (i == n) {
        ans = min(ans, abs(sum-2*cursum));
        return;
    }
    dfs(i+1, cursum+w[i]);
    dfs(i+1, cursum);
}
int main()
{
    while (scanf("%d", &n) != EOF) {
        sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w[i]);
            sum += w[i];
        }
        ans = INF;
        dfs(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}

/*dp*/
#include <iostream>
#include <cstdio>
#include <cstring>                  //for memset 
#include <algorithm>                //for max
using namespace std;
const int M = 20 + 5;
int w[M];
int dp[M*100000];
int main()
{
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &w[i]);
            sum += w[i];
        }
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i)
            for (int j = sum/2; j >= w[i]; --j)
                dp[j] = max(dp[j], dp[j-w[i]] + w[i]);
        printf("%d\n", sum - dp[sum/2]*2);
    }
    return 0;
}
