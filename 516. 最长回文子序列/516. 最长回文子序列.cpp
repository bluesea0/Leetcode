#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��8������5:49:07
//class Solution {
//public:
//    int longestPalindromeSubseq(string s) {
//        int m=s.size();
//        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
//        for(int j=m;j>0;j--){//�Ӻ���ǰ����
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
 * 1.�������֮����Ϊ�ܺܿ�д������������˼·����reverse֮�������������У������������ֱ�ӴӺ���ǰ
 *   ���������ұ������£��Ҳ����ˣ���Ȼdp����dp����
 * 2.����дһ����������е����⡣�������棬������ƽ������ģ���Ҫ��������dp���顣
 * */
class Solution {
public:
   int longestPalindromeSubseq(string s) {
       int m=s.size();
       vector<vector<int>> dp(m+1,vector<int>(m+1,0));
       string t=s;
       reverse(s.begin(),s.end());
       for(int j=1;j<=m;j++){//�Ӻ���ǰ����
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
 * 1.�����dp���µĻ���ֻ��Ҫ�����°�����ǣ�i�Ӻ���ǰ���£�j��i+1��ʼ����ǰ������£���Ϊ�����ʱ����õ�
 *   j-1��i����ʱ��Ҫ�õ�i+1�����ԴӺ���ǰ���㡣
 * */
class Solution {
public:
   int longestPalindromeSubseq(string s) {
       int m=s.size();
       vector<vector<int>> dp(m,vector<int>(m,0));
       //dp[i][j]��ʾs[i:j]��������Ӵ�
       for(int i=m-1;i>=0;i--){//�Ӻ���ǰ����
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
