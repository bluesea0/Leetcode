#include <iostream>
#include<vector>
#include<queue>
using namespace std;
//10-12
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid);//通过这样来复制这个数组的值。
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){//不要写错i/j好吗，导致了死循环，真有你的。
                if(i==0&&j==0)continue;
                if(i==0)
                    dp[i][j]=dp[i][j-1]+dp[i][j];
                else{
                    if(j==0)dp[i][j]=dp[i-1][j]+dp[i][j];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1])+dp[i][j];
                }
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};
/*
1.AC了，还是比较基础的DP，其实写的时候我就想到了可以只创建一维的数组因为这样的话，我不会写
那个推导公式，评论里有，我看一下。
2.评论有个给了多申请一行空间，就能更快一点。
int[][] dp = new int[row + 1][column + 1];
3.辅助一维数组，即滚动数组，这个解法绝了
https://blog.csdn.net/qq_15711195/article/details/96995494
下次复习的时候要看一下。
*/
//10-12
class Solution1 {
public:
    int maxValue(vector<vector<int>>& grid) {
        //通过一维的滚动数组来完成
        vector<int> dp(grid[0]);
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){//i或j=0了怎么办？
                if(i==0 && j==0)continue;
                if(i==0){
                    dp[j]=dp[j-1]+grid[i][j];
                }else{
                    if(j==0)
                        dp[j]+=grid[i][j];
                    else
                        dp[j]=max(dp[j-1],dp[j])+grid[i][j];
                }
            }
        }
        return dp[n-1];
}};
/*
1.我上面写的这个使用滚动数组也AC了，但是咋写的这么麻烦呢。
2.上面链接的代码
class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        if(board.empty()) return 0;
        int n = board[0].size();
        vector<int> dp(n);//当在第0行的时候，初始化为0，dp[i]相当于加上了0，绝了绝了，膜拜。
        for(auto val: board) {
            dp[0] += val[0];
            for(int i=1; i<n; ++i) dp[i] = max(dp[i], dp[i-1])+val[i];

        }
        return dp[n-1];
    }
};
真的牛批，从这个代码就能看出来这算法功力深厚啊！不是一般人。
*/

//10-22
//复习一下，写了出来，还是要再复习一下感觉，如果丢了这个宝藏可不太好了。
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {//对边界值的判定
        vector<int> dp(grid[0].size(),0);
        for(auto g:grid){
            dp[0]+=g[0];
            for(int j=1;j<grid[0].size();j++){
                dp[j]=max(dp[j],dp[j-1])+g[j];
            }
        }
        return dp[grid[0].size()-1];
    }
};

//5-26
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        //在评论区里看到有多申请一行空间，然后下标遍历就很方便，但是我反应不过来
        //那更新的时候岂不是要grid[i-2]了？那如果长度才是1，这样不就访问不存在的下标了？？
        //看了题解之后我懂了，你还是没关注转移方程
        //dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1]，并不会对grid访问到i-2或j-2
        //如果不多申请的话，那么转移方程就是：
        //dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i][j];
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+grid[i-1][j-1];
            }
        }
        return dp[m][n];
    }
};//这个关于多申请一行一列的需要再掌握。
//空间优化版本
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> dp(n,0);
        dp[0]=grid[0][0];
        for(int i=1;i<n;i++)
            //dp[i]=grid[0][i];//这里初始化有问题，应该是累加和啊
            dp[i]=dp[i-1]+grid[0][i];
        for(int i=1;i<m;i++){
            // for(int j=n-1;j>=0;j--){
            //     dp[j]=max(dp[j],dp[j-1])+grid[i][j];
            // }//就是从前往后更新啊，我的天，我在想什么？？？
            for(int j=0;j<n;j++){
                if(j==0)
                    dp[j]+=grid[i][j];
                else
                    dp[j]=max(dp[j],dp[j-1])+grid[i][j];
            }
        }
        return dp.back();
    }
};
/*
 * 1.也是遇到了很多小问题，太恐怖了啊。我做这道题是想象着面试官在屏幕对面看着我打代码，我就紧张啊，
 *   我思路就不敢多想，怕想错从而出错，那就忽略面试官吧，就当作一次刷题了。
 * 2.初始化问题、倒序更新？这又不是什么股票问题，正常是正序更新，所以就不要看到一道dp题在空间优化了
 *   就直接说j要倒序更新，你不必要那么快给出来，根本不经过大脑思考？太紧张了，怕空白。
 * */
int main(){
    Solution1 s;
    vector<vector<int>> g={{1,3,1},{1,5,1},{4,2,1}};
    cout<<s.maxValue(g);
    return 0;
}
