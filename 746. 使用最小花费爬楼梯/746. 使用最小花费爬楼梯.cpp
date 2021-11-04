#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月21日下午1:41:00
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),0);
        int m=dp.size();
        dp[0]=cost[0];
        dp[1]=cost[1];//dp[i]表示的是跳到当前为止的最低花费，是个子问题
        for(int i=2;i<m;i++){
            //选择：从i-2挑2步到当前位置
            // 从i-1跳1步到当前位置
            // 从i-1跳2步到下一位置，并且这个跳到下一位置怎么处理呢？这一下子就加上下一位置？
            //不应该加
            //dp[i]=min(min(dp[i-2]+cost[i],dp[i-1]+cost[i]),dp[i-1]);//但是如果这么写的话
            //就不用比较什么了，第三个肯定要第二项小的啊。
            //而且还有一个问题：样例1中是跳2步到数组外了，样例2是正好跳到最后一个元素上
            //这两种差异的情况下如何判断呢？我自顶向下是否可行？
            dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
        }
        return min(dp[m-1],dp[m-2]);
    }
};//AC了，比较开心，不过过程中还差点遇到问题，主要是对问题的分析不透彻导致的。

class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //进行空间的优化
        int dp0=cost[0],dp1=cost[1];
        for(int i=2;i<cost.size();i++){
            int t1=min(dp0+cost[i],dp1+cost[i]);
            dp0=dp1;
            dp1=t1;
        }
        return min(dp0,dp1);
    }
};//我都老忘记。。。
int main(){

    return 0;
}
