#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月17日下午2:54:41
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //思路：相当于计算数组中所有递增子序列的和
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
                ans+=(prices[i]-prices[i-1]);
        }
        return ans;
    }
};//AC了，当然是因为我之前看了题解，不看的话我是不懂的。这个是贪心的方法，还有dp的方法。

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        //思路：使用dp的话，需要分状态，dp[i][0]表示第i天不持有股票的最大利润，
        //dp[i][1]表示第i天持有股票的最大利润。
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=0;dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);//前一天没有，前一天有今天卖出
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);//前一天有，前一天没有今天买
        }
        return dp[n-1][0];
    }
};
/*
 * 1.使用dp的方法，当然发现上面其实是不用二维数组的，只需记录上一天的两个状态。
 * */
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        //思路：使用dp的话，需要分状态，dp[i][0]表示第i天不持有股票的最大利润，
        //dp[i][1]表示第i天持有股票的最大利润。
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        int dp0=0,dp1=-prices[0];
        for(int i=1;i<n;i++){
            int d0=max(dp0,dp1+prices[i]);
            int d1=max(dp1,dp0-prices[i]);
            dp0=d0;
            dp1=d1;
        }
        return dp0;
    }
};//这个实在是挺慢的！
int main(){

    return 0;
}
