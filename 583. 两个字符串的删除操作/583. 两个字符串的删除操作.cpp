#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年1月28日下午7:48:01
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> edit(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++)
            edit[i][0]=i;
        for(int j=0;j<=n;j++)
            edit[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    edit[i][j]=edit[i-1][j-1];
                else edit[i][j]=min(edit[i-1][j],edit[i][j-1])+1;
            }
        }
        return edit[m][n];
    }
};
/*
 * 1.只要会了编辑距离，这个根本不是问题，这个只有删除操作，没有更改操作。
 * 2.绝了，看了题解，上面编辑距离的写法，还可以使用滚动数组。还有另一种思路是求最长公共子序列。
 * */

//1-29
/*
 * 1.先来写一下使用滚动数组+编辑距离求解的方法，再写一下使用LCS的解法。
 * */
class Solution2 {
public:
    int minDistance(string word1, string word2) {
        int n=word2.size();
        vector<int> dp(n+1,0);
        for(int i=0;i<=n;i++)
            dp[i]=i;
        for(int i=1;i<=word1.size();i++){
            vector<int> t(n+1,0);//先定义一个临时的
            for(int j=0;j<=n;j++){
                if(j==0){t[j]=i;continue;}
                if(word1[i-1]==word2[j-1])
                    t[j]=dp[j-1];
                else
                    t[j]=min(t[j-1],dp[j])+1;
            }
            dp=t;
        }
        return dp.back();
    }
};
//LCS解法：
class Solution3 {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector<vector<int>> lcs(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    lcs[i][j]=lcs[i-1][j-1]+1;
                else lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);//分别表示删除i或j
            }
        }
        return m+n-2*lcs[m][n];
    }
};
/*
 * 1.都是O(mn)的解法，运行时间都是类似的。当然这个也可以用滚动数组。
 * */
int main(){

    return 0;
}
