#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月11日下午6:55:23
class Solution {
public:
    int numSquares(int n) {
        //状态转移方程，枚举dp[i]=1+min(dp[i-j^2]),j>=1&&j*j<=i;
        //这个状态转移方程就是最贵的东西啊
        vector<int> dp(n+1,n+1);
        dp[0]=0,dp[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp.back();
    }
};
/*
 * 1.当然，我自己是没有写出来状态转移方程的。就很乱，人家写出来就感觉好神奇。
 * */
int main(){

    return 0;
}
