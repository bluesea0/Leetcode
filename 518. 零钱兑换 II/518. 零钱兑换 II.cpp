#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021年2月20日下午4:36:50
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        //其实这个和322非常像，只不过不是求最小值，而是求组合数！
//        //dp[i]+=dp[i-c]
//        //哇塞，不对，我这种写法是排列数啊，也不是组和数，我哭了！
//
//        //dp[i]=max(dp[i],dp[i-c])???这个可以吗？这个也不对，这样的话怎么计数呢？
//        //我是真的不会了！
//
//        vector<int> dp(amount+1,0);
//        dp[0]=1;//这里赋值为1表示如果有减到这里的数值表示能有1个，表示它本身
//        for(int i=1;i<=amount;i++){//没有意识到是排列还是组和问题，真是头一次学啊
//            for(auto c:coins){
//                if(c>i)continue;
//                //if(dp[i]==INT_MAX)//这里的初始化似乎就有问题了
//                    //dp[i]=1;//它这是计算能有几种，而不是最少能由几个形成
//                //关键还是状态方程的更新
//                //dp[i]+=dp[i-c];
//                dp[i]=max(dp[i],dp[i-c]);
//            }
//        }
//        return dp[amount]==INT_MAX?0:dp[amount];
//    }
//};
/*
 * 1.看了题解：将物品放在外面循环是组和问题，将容量放在外面循环是排列问题！
 * 2.和70题爬楼梯类似，但是70是排列问题，本题是组和问题。
 * */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;//这里赋值为1表示如果有减到这里的数值表示能有1个，表示它本身
        for(auto& c:coins){//如果先遍历它=固定了硬币的大小顺序，是组合问题
            for(int i=1;i<=amount;i++){//这里的i可以直接初始化为c！就省得写里面的continue语句了！绝！
                if(c>i)continue;
                dp[i]+=dp[i-c];
            }
        }
        return dp[amount];
    }
};
/*
 * 3.AC了，https://www.cnblogs.com/grandyang/p/7669088.html这里讲了初始未优化的方程：
 *   dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0)
 *   i是枚举硬币，到当前容量j的时候，结果包括：不包含当前硬币时组成j的数目+包含当前硬币i时组成j的数目
 * */

//3-25
/*
 * 1.还是有难度的，将物品放在外层循环，每个容量只会放一次，是个组和问题；将物品放在内层循环，每个容量都会对
 *   每个物品放一次，而不管之前的容量已经包含了该物品，所以就是排列问题。
 * */

//6-11
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //先遍历硬币保证不重复，每种金额出现的顺序给固定了
        if(amount==0)return 1;
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(auto &c:coins){
            for(int i=1;i<=amount;i++){
                if(c>i)continue;
                dp[i]=dp[i]+dp[i-c];
            }
        }
        return dp.back();
    }
};//还是要多复习啊。
int main(){

    return 0;
}
