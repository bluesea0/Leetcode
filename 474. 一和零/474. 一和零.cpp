#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月17日下午4:57:22
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        //dp[i][j]表示的是有i个0和j个1的情况下，最大的子集大小
//        //其实我一看到这个题就想的是strs的前n个元素最多能有几个0几个1，那这样是3维数组，而且是
//        //必须要有strs.size()行，m个列，然后第三维是n，就表示从前i个元素里最多包含了j个0和k个1
//        //但是这样好像只能实现一个计数的功能，只是对每个元素的0、1数目统计了一下
//        //其实这里m和n就相当于两个背包啊！
//    }
//};
/*
 * 1.还以为我上面的分析错了呢，没想到没错啊！确实是没错的，参考https://www.cnblogs.com/grandyang/p/6188893.html
 *   评论区的一楼解法，状态是有三个的，物品、背包0、背包1，首先其实是个三维的问题，之后的空间优化
 *   转换为二维，而由于是0-1背包问题所以需要从大到小更新。dp[i][j][k]表示在子区间[0,i]包含j个0k个1的
 *   字符串的最大数量。（其实这个时候可能能满足j，不满足k，也有可能都满足，只是最多的情况）这个两个
 *   背包是互相牵制的。
 * */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp[i][j][k]=max(dp[i-1][j-x][k-y]+1,dp[i-1][j][k]);//放或者不放
        //优化空间后，0-1背包问题需要逆序遍历
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<strs.size();i++){//遍历每个物品看是否能放进去
            auto ct=helper(strs[i]);
            for(int j=m;j>=0;j--){//对应0的个数
                for(int k=n;k>=0;k--){//对应1的个数
                    if(j>=ct[0]&&k>=ct[1])
                        dp[j][k]=max(dp[j][k],dp[j-ct[0]][k-ct[1]]+1);
                        //每次下面都要依赖于上面的更新，上面三维的是又多存了一层
                        //正向更新会出错的！
                    else break;
                }
            }
        }
        return dp[m][n];
    }
    vector<int> helper(string& s){
        int x=0,y=0;
        for(auto& c:s){
            if(c=='0')x++;
            else y++;
        }
        return {x,y};
    }
};
/*
 * 1.0-1背包解法实在是有点难啊！复杂度就是三层for循环乘积
 * */
int main(){

    return 0;
}
