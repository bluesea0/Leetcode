#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月29日下午4:59:34
//class Solution2 {
//public:
//    int minimumDeleteSum(string s1, string s2) {
//        //好难，这是编辑距离的升级吗？太难了吧。
//        int m=s1.size(),n=s2.size();
//        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//        for(int i=1;i<=m;i++)//前缀ASCII和
//            dp[i][0]=dp[i-1][0]+s1[i-1];//这样直接将字符作为int运算是ok的
//        for(int j=1;j<=n;j++)
//            dp[0][j]=dp[0][j-1]+s2[j-1];
//        for(int i=1;i<=m;i++){
//            for(int j=1;j<=n;j++){
//                //每次删除时都保留较大的
//                if(s1[i-1]==s2[j-1])
//                    dp[i][j]=dp[i-1][j-1]+s[i-1];
//                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]+s2[j-1]);
//            }
//        }
//        for(int i=0;i<=m;i++){
//            for(int j=0;j<=n;j++){
//            	cout<<dp[i][j]<<" ";
//            }
//            cout<<endl;
//        }
//        return dp[m][0]+dp[0][n]-dp[m][n];
//    }
//};//我这个思路是错误的，有两种思路，一种是正向的计算最小，一种是反向的计算LCS的最大ASCII码。
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //好难，这是编辑距离的升级吗？太难了吧。
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // for(int i=1;i<=m;i++)//前缀ASCII和
        //     dp[i][0]=dp[i-1][0]+s1[i-1];//这样直接将字符作为int运算是ok的
        // for(int j=1;j<=n;j++)
        //     dp[0][j]=dp[0][j-1]+s2[j-1];
        //保留LCS中ASCII值最大的
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                //每次删除时都保留较大的
                if(s1[i-1]==s2[j-1])//说明当前要保留
                    dp[i][j]=dp[i-1][j-1]+s1[i-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ct1=accumulate(s1.begin(),s1.end(),0);
        int ct2=accumulate(s2.begin(),s2.end(),0);
        return ct1+ct2-2*dp[m][n];
    }
};
/*
 * 1.将上面的思路更改了一下。dp[i][j]保存的是两个字串中LCS中的最大ASCII值，那么一开始就只能初始化为0.
 * 2.下面的思路是直接求，dp[i][j]表示删掉的字符串的ASCII值最小
 * */
class Solution2 {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)//前缀ASCII和
            dp[i][0]=dp[i-1][0]+s1[i-1];//这样直接将字符作为int运算是ok的
        for(int j=1;j<=n;j++)
            dp[0][j]=dp[0][j-1]+s2[j-1];
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1])//说明当前不删除
                    dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);//那么就选择其中A值较小的删除。
            }
        }
        return dp[m][n];
    }
};
int main(){
	Solution s;
	cout<<s.minimumDeleteSum("s", "ea");
    return 0;
}
