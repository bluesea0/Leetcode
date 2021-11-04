#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年6月11日上午11:17:42
class Solution {
public:
    bool isMatch(string s, string p) {
        //dp[i,j]表示s的第i个字符和p中的第j个是否匹配
        /*
        1.当s[i]==p[j] dp[i][j]=dp[i-1][j-1]
        2.当p[j]==? dp[i][j]=dp[i-1][j-1]
        3.当p[j]==* dp[i][j]=dp[i-1][j]|dp[i][j-1]

        base case:
        若s.size()==0，那么p前几个字符是*为true，否则为false
        若p.size()==0，s==0为true，否则为false。
        */
        int m=s.size(),n=p.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=0;i<n;i++)
            if(p[i]=='*')dp[0][i+1]=1;
            else break;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(s[i]==p[j])dp[i+1][j+1]=dp[i][j];//妈呀原来是下标搞错了
                else if(p[j]=='?')dp[i+1][j+1]=dp[i][j];
                else if(p[j]=='*')dp[i+1][j+1]=dp[i][j+1]||dp[i+1][j];//匹配*||不匹配*，*表示空串
            }
        }
        return dp[m][n];
    }
};
/*
 * 1.真tm的是命途多舛，遇到了好几个小问题。
 * 2.首先是状态更新的理解，当p[j]为*的时候，如果用到j那么就是dp[i-1][j]，j并没有动此时，说明要用j去匹配
 *   前面的i-1个字符，而且目前已经用到了j，所以就实现了匹配多个字符；如果没有用j，那么就是j目前匹配了
 *   空串。
 * 3.for循环时p的下标写错了，最后一个else仍然需要判断，否则"ab""?c"这样的因为b！=c但是并没有判断p是否为
 *   *，就会导致出错。
 * */

//9-20
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        //dp[i][j]表示s的前i个字符和p的前j个字符能否匹配

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            if(p[i-1]=='*')dp[0][i]=1;
            else break;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*')
                    dp[i][j]=dp[i][j-1]||dp[i-1][j];
            }
        }
        return dp[m][n];
    }
};
/*
 * 1.复习了一些写法。关键点在于是dp[i][j]表示s的前i个字符和p的前j个字符能否匹配。
 * */
int main(){

    return 0;
}
