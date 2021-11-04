#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月21日下午1:53:58
//初次提交
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,1);
        for(int i=2;i<dp.size();i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp.back();
    }
};
//优化空间后，超过了100%。
class Solution2 {
public:
    int climbStairs(int n) {
        if(n<2)return n;
        int dp0=1,dp1=1;
        for(int i=2;i<n+1;i++){
            int t=dp0+dp1;
            dp0=dp1;
            dp1=t;
        }
        return dp1;
    }
};

//2-20
class Solution3 {
public:
    int climbStairs(int n) {
        //使用完全背包思想来求解
        vector<int> stairs={1,2};
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){//排列问题，遍历每个容量，考虑物品顺序
            for(int j=0;j<stairs.size();j++){
                if(stairs[j]>i)continue;
                dp[i]+=dp[i-stairs[j]];
            }
        }
        return dp[n];
    }
};
/*
 * 1.虽然这样写很低效，但是这个是统一的完全背包问题求排列数的解法，在学习了518题之后过来的。
 * */
int main(){

    return 0;
}
