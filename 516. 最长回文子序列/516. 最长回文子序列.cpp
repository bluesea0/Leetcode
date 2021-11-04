#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月8日下午5:49:07
//class Solution {
//public:
//    int longestPalindromeSubseq(string s) {
//        int m=s.size();
//        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
//        for(int j=m;j>0;j--){//从后往前遍历
//            for(int i=1;i<=m;i++){
//                if(s[j-1]==s[i-1])
//                    dp[i][j]=dp[i-1][j-1]+1;
//                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//            }
//        }
//        return dp[m][m];
//    }
//};
/*
 * 1.看了题解之后本以为能很快写出来，本来的思路是求reverse之后的最长公共子序列，但是题解中是直接从后往前
 *   遍历，而且遍历很懵，我不懂了，果然dp还是dp啊。
 * 2.我先写一下用最长子序列的来解。解在下面，这样是平方级别的，需要更新整个dp数组。
 * */
class Solution {
public:
   int longestPalindromeSubseq(string s) {
       int m=s.size();
       vector<vector<int>> dp(m+1,vector<int>(m+1,0));
       string t=s;
       reverse(s.begin(),s.end());
       for(int j=1;j<=m;j++){//从后往前遍历
           for(int i=1;i<=m;i++){
               if(s[j-1]==t[i-1])
                   dp[i][j]=dp[i-1][j-1]+1;
               else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
       return dp[m][m];
   }
};
/*
 * 1.如果是dp更新的话，只需要更新下班个三角，i从后往前更新，j从i+1开始，从前往后更新，因为计算的时候会用到
 *   j-1，i计算时需要用到i+1，所以从后往前计算。
 * */
class Solution {
public:
   int longestPalindromeSubseq(string s) {
       int m=s.size();
       vector<vector<int>> dp(m,vector<int>(m,0));
       //dp[i][j]表示s[i:j]的最长回文子串
       for(int i=m-1;i>=0;i--){//从后往前遍历
            dp[i][i]=1;
           for(int j=i+1;j<m;j++){
               if(s[j]==s[i])
                   dp[i][j]=dp[i+1][j-1]+2;
               else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
           }
       }
       return dp[0][m-1];
   }
};
int main(){

    return 0;
}
