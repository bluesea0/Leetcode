#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年3月2日上午10:39:02
class NumMatrix {
public:
    vector<vector<int>> dp;
    NumMatrix(vector<vector<int>>& matrix) {
//         ["NumMatrix"]
// [[[]]] 会有空数组的情况，没有考虑啊
        int m=matrix.size();
        if(m==0)return;
        int n=matrix[0].size();//是这个地方的问题啊！n无法求得的！
        //空数组的话是无法访问第0个元素的！！！！我之前没有考虑到过这个情况。
        if(n==0)return;
        dp.resize(m,vector<int>(n,0));
        dp[0][0]=matrix[0][0];
        for(int i=1;i<m;i++)
            dp[i][0]=dp[i-1][0]+matrix[i][0];
        for(int j=1;j<n;j++)
            dp[0][j]=dp[0][j-1]+matrix[0][j];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1]+matrix[i][j]-dp[i-1][j-1];//这里最后需要减去，否则就多计算了
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int m=dp.size(),n=dp[0].size();
        if(row1>=m||row2>=m||col1>=n||col2>=n)return 0;//判断下标不合适的情况
        if(row1==0&&col1==0)return dp[row2][col2];
        if(row1==0)return dp[row2][col2]-dp[row2][col1-1];//[0,1][4,3]
        if(col1==0)return dp[row2][col2]-dp[row1-1][col2];//【2.0】[4,3]
        return dp[row2][col2]-dp[row2][col1-1]-dp[row1-1][col2]+dp[row1-1][col1-1];
    }
};
/*
 * 1.思路还是比较简单的，需要计算累积数组，但是出现了两个错误。
 * 2.看了题解才知道这个思路叫二维前缀和，而且更简洁的写法是建立+1的数组，这样就不用额外考虑=0的情况了。
 * */
class NumMatrix2 {
public:
    vector<vector<int>> sums;
    NumMatrix(vector<vector<int>>& matrix) {
        if(matrix.size()==0)return;
        int m=matrix.size(),n=matrix[0].size();
        sums.resize(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                sums[i][j]=sums[i-1][j]+sums[i][j-1]+matrix[i-1][j-1]-sums[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1]-sums[row1][col2+1]-sums[row2+1][col1]+sums[row1][col1];
    }
};
/*
 * 1.照着官方题解写了一下，果然前缀和数组大小要+1，操作才简洁。
 * */
int main(){

    return 0;
}
