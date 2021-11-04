#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//10-19
/*
1.我感觉蛮难的，看标签是个动态规划的题目？但是我只能想到类似DFS的那种。。。好笨啊。
  怎么写dp呢？转移表达式又是什么呢？我感觉我没做过这道题吧。。。好难的。。
2.我有一丝印象了，肯定要先从大的开始减起，但是如果大的减多了？想起来了，先计算每种硬币数最少的
*/
class Solution {
public:
    int ans=-1;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        ans=amount+1;
        coin(0,0,0,coins,amount);
        return ans==amount+1?-1:ans;
    }
    void coin(int index,int sum,int ct,vector<int> coins, int amount){
        if(sum==amount){
            ans=min(ans,ct);
            return;
        }
        if(index==coins.size())return;
        int k=(amount-sum)/coins[index];
        for(int i=k;i>=0;i--){//依次递减。
            if(i+ct<ans)//这里的判断非常重要，是剪枝的作用。
                coin(index+1,sum+i*coins[index],ct+i,coins,amount);
            else break;//这里加了break之后就通过了。不然还是会超时的
        }
    }
};
/*
1.[3,7,405,436]
8839
这个样本超出时间限制。是不是上面的for循环不能从k->0，因为这样导致次数会非常多？
但是如果不每次循环的话，怎么保证可以后面的能够补上呢？这是一个矛盾啊！
[277,196,194,358,263,257]
7477
修改之后上例还是会超出时间限制。。。
[208,170,205,425,124,375]
7130
这个样本又超时了。。。绝了。。。
2.但是这个解法其实不是dp解法，而是DFS+剪枝的解法。
3.https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/
  官方的解法，我觉得还是自底向上比较好理解，自顶向下其实也是一个递归。
*/

//10-22
class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        //dp[i]表示的是总金额为i时所需的最少硬币数目
        for(int i=1;i<=amount;i++){
            for(auto coin:coins){
                if(i<coin)continue;
                dp[i]=min(dp[i-coin]+1,dp[i]);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
}};
/*
1.Yes!!AC了！然后我再写一下自顶向下的。但是这个运行的时间真的有点长嘞。
*/
class Solution2 {
public:
    vector<int> dp;
    int coin(vector<int>& coins,int am){//这里就传递引用吧，不希望coin被更改的意思。
        if(am==0) return 0;
//        if(am<0) return -1;//负数的，负数表示的是无法组成。
        //注释掉上面这句是是可以的，因为下面for循环中在调用coin的时候我做了判断。
        if(dp[am]!=INT_MAX) return dp[am];
        for(auto c:coins){
            if(am-c>=0){
                int t=coin(coins,am-c);
                if(t>=0)
                    dp[am]=min(dp[am],t+1);
            }
        }
        dp[am]=dp[am]==INT_MAX?-1:dp[am];
        return dp[am];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount<=0) return 0;//需要加上这个判断。
        dp.resize(amount+1,INT_MAX);
        coin(coins,amount);
        return dp[amount]==INT_MAX?-1:dp[amount];
    }};
/*
2.[1,2,5]
100。超出时间限制，我这个递归出口写的有问题啊。。。
3.我之前有在想，需不需要排序，但是看了一圈，没有需要排序的。
4.{1}，0没过，这是为什么呢。
5.上面写的终于AC了，太不熟练了，提交了4次才通过。。。真的需要多复习，已经安排了。
*/

//10-23
/*
1.这次复习来看一下复杂度：O(Sn)，其中 S是金额，n 是面额数。
  ：O(S)，我们需要额外开一个长为 S 的数组来存储计算出来的答案
2.就照我solution2的解法，是否要加m<0?和t>=0的判断，其实是需要的，如果是这样的[2],3样例，
  调用的过程中会到coin(1)，这样的话因为没有进入硬币的循环，会返回-1，就需要判断t>=0
  如果我直接dp函数中修改返回的值，不返回-1，那么在执行[2],3的时候就会遇到NT_MAX+1溢出的问题
  所以按照我的初始化方法，就必须按照上面的来写，真挺麻烦的，我看看官方的怎么写。
  官方的写法和我基本一致，就是需要判断amount<0?则返回-1，然后还要对返回的值判断>0？，就是针对凑不
  上的样本。
*/

//2-20
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        //我就写个最简单的完全背包吧，不优化空间的解法
//        //但是要申请空间的话，我就有点害怕了，会不会空间不够用，因为amount最大值为10000
//        if(amount==0) return 0;
//        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
//        //dp[i][j]表示由[0,i]种硬币能组和成amount的最少硬币个数
//        //状态转移方程：dp[i][j]=min(dp[i-1][j-k*nums[i]]+k) k的大小保证下标值为正
//        //base case：dp[i][0]=0,
//        //那按照这么说就有三层循环了？
//    }
//};
class Solution4 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        //vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        //完全背包问题没有物品的状态？只有容量？
        //dp[i]表示容量为i时所需的最少硬币个数,dp[i]=min(dp[i-coins[j]]+1)
        //其实背包问题的容量肯定都是j-weight[i]这样来递推的！
        vector<int> dp(amount+1,amount+1);//表示最多都是由1组成的
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]>i)continue;
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];//这里是需要考虑组不成的情况
    }
};
/*
 * 1.按照完全背包写的AC了，我太开心了吧呜呜呜。我觉得就这个最简单了，够了够了。
 * */

//6-11
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        /*
//        dp[i][j]表示前i种硬币能组成j总额的最少硬币个数
//        dp[i][j]=min(dp[i-1][j],dp[i-1][j-k*nums[i-1]]);
//        */
//        int n=coins.size();
//        vector<vector<int>> dp(n+1,vector<int>(amount+1,amount+1));
//        //dp[0][0]=0;
//        for(int i=0;i<=n;i++)
//            dp[i][0]=0;
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=amount;j++){
//                if(coins[i-1]>j)dp[i][j]=dp[i-1][j];
//                else dp[i][j]=min(dp[i-1][j],dp[i-1][j-coins[i-1]]+1);
//            }
//        }
//        return dp[n][amount];
//    }
//};
/*
 * 1.写着写着没写出来，难道是完全背包问题就只用dp[j]表示amount就好了？因为完全背包两维的不好解决，
 *   所以转化为一维的，使用01背包来解决。太难了。
 * */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto& c:coins){
                if(c>i)continue;
                dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
        return dp.back()==amount+1?-1:dp.back();
    }
};
/*
 * 1.终于又根据完全背包的思想来解决了。太不容易了。
 * */

//9-18
/*
 * 1.0-1背包问题，外层遍历物品，内层从大到小遍历容量；（因为只能用一次）
 *   完全背包问题，外层遍历物品，内层从小到大遍历容量。（能用多次）
 * */
int main(){
    Solution4 s;
    vector<int> v={2};
    cout<<s.coinChange(v,3);//针对这个样本的话，它对不上，然后就会死循环了，没有出口，所以要添加一个
    return 0;
}
