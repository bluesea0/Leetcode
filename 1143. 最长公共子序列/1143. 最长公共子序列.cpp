#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年10月2日上午11:50:33
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        //base case是在i=0或j=0时，即两个字符串有一个为空时，那么默认初始化为0
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};
/*
 * 1.一开始没有想到用dp方法来解，想的是用两个指针指向两个数组，然后遍历，后来发现应该不行。
 *   看了题解之后，恍然大悟，简单dp。
 * */
int main(){

    return 0;
}
