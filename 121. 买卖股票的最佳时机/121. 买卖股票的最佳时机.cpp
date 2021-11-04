#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月17日下午2:48:52
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //忽然看到这个还真是差点不会，但是想起来了，遍历过程中计算最低价，对每个进行-操作。
        if(prices.size()==0) return 0;
        int minp=prices[0],res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minp)//这里可以直接换为minp=min(minp,prices[i])多简单。
                minp=prices[i];
            res=max(res,prices[i]-minp);
        }
        return res;
    }
};//AC了

//12-7复习
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        //思想：dp二维数组，每天都有两种状态，持有或不持有，所获得的最大利润
//        //持有dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i])
//        //不持有dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
//        //那么目前就存在一个问题，怎么限制只交易一次？又难住我了！！
//        if(prices.size()==0)return 0;
//        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
//        dp[0][0]=0;dp[0][1]=-prices[0];
//        for(size_t i=0;i<prices.size();i++){
//            //脑袋一片空白，因为我认为上述的公式中无法限制交易次数！
//        }
//    }
//};
/*
 * 1.这次复习我的感觉就是，我真是个傻逼啊！装什么逼啊呜呜呜，mlgb的。
 * 2.官方题解种给的暴力法，O(n^2)的，我才明白，我根本就没有理解这道题具体在解决什么问题！
 *   找j>i的最大差值，并且j要在i后，那么对每个i，判断每个右j就行了啊！
 * */

//12-23
/*
 * 1.贪心思想：比较简单，获取一个最小值和最大值，并且最大值要在最小值后面。获取最大的差值。
	dp：不会，因为如何表示限制一次交易呢？
 * */
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0)return 0;
        int m=prices[0],res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>m)
                res=max(res,prices[i]-m);
            else
                m=prices[i];
        }
        return res;
    }
};//当然这个和上面的解法思路是一样的啊。看了官方和grand都是这么个思路，算了就这样吧。

//2021-6-18
/*
 * 1.今天再复习这道题，没想到半年过去了，我还是想不通用dp的时候该怎么解决只能买卖一次的问题。
 *
public int maxProfit(int[] prices) {
        if (prices.length < 2) return 0; // 没有卖出的可能性
        // 定义状态，第i天卖出的最大收益
        int[] dp = new int[prices.length];
        dp[0] = 0;  // 初始边界
        int cost = prices[0]; // 成本
        for (int i = 1; i < prices.length; i++) {
            dp[i] = Math.max(dp[i - 1], prices[i] - cost);
            // 选择较小的成本买入
            cost = Math.min(cost, prices[i]);
        }

        return dp[prices.length - 1];
    }
    在评论区里看到的解法，没有使用二维的状态数组，关键定义的点是
	dp[i]表示第i天及之前卖出能获得的最大利润
 * */
int main(){

    return 0;
}
