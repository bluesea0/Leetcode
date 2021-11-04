#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月8日下午10:26:09
class Solution {
public:
    int minInsertions(string s) {
        //相当于求最长回文子序列
        //再由它计算结果
        //dp[i][j]表示s[i:j]最长回文子串
        //dp[0][n-1]表示s[0:n-1]的最长回文子串
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            dp[i][i]=1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return n-dp[0][n-1];
    }
};
/*
 * 1.官方题解中，我不太懂为什么区间dp时，状态转移时为什么要那样？明天学习一下区间dp的解法。
 * */

//10-10
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len=2;len<=n;len++){//区间dp，枚举长度
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;//在i中插入s[j]或者在j中插入s[i]
            }
        }
        return dp[0][n-1];//dp[i][j]表示在s的[i,j]之间
    }
};
/*
 * 1.区间dp的解法。枚举len及起点，然后计算j，也算是比较好理解，但是需要多做题巩固才行。
 * */
int main(){

    return 0;
}
