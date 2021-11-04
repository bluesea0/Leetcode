#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月22日下午7:32:41
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)return 0;
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int j=1;j<n;j++)
            dp[0][j]=dp[0][j-1]+grid[0][j];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
/*
 * 1.比较简单，下面进行空间的优化。
 * */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)return 0;
        int n=grid[0].size();
        //vector<int> dp=grid[0];//初始化有问题
        vector<int> dp(n);
        dp[0]=grid[0][0];
        for(int j=1;j<n;j++)
            dp[j]=dp[j-1]+grid[0][j];
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0)
                    dp[j]=dp[j]+grid[i][j];
                else dp[j]=min(dp[j],dp[j-1])+grid[i][j];
            }
        }
        return dp[n-1];
    }
};

int main(){

    return 0;
}
