#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月22日下午1:33:57
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //三种状态：持有、没持有、冷冻期
        size_t m=prices.size();
        if(m==0) return 0;
        vector<vector<int>> dp(m,vector<int>(3,0));//[m,3]
        //base case
        dp[0][1]=-prices[0];//第0天持有股票
        // dp[0][2]=0;//第0天处于冷冻期，那是不可能的
        for(size_t i=1;i<m;i++){
            //第i天不持有股票且不处于冷冻期，说明i-1天不持有股票
            //那么可能i-1天处于冷冻期，i-1天不处于冷冻期
            dp[i][0]=max(dp[i-1][2],dp[i-1][0]);

            //第i天持有股票
            //i-1天也持有股票，i-1天不持有且不处于冷冻期
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);

            //第i天持有股票，且当天卖出，那么第i-1天就处于冷冻期了
            dp[i][2]=dp[i-1][1]+prices[i];//天啦，这个冷冻期怎么更新？它应该是被动的啊
            //害你说就像这么麻烦的dp题，我怎么运行样例啊。
        }
        return max(dp[m-1][0],dp[m-1][2]);//是这样？
    }
};
/*
 * 1.AC了，但我想说这个真的好难啊！
 *   https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/
 *   官方题解写的非常好，我其实看了两边题解之后还是没写出来，主要是对dp数组的表示还是不清楚，理解有问题。
 * 2.关于冷冻期，dp[i][2]处于冷冻期表示的是第i天结束后的状态，第i天结束之后的状态，第i+1天不能买股票
 *   那么dp[i][0]表示不处于冷冻期，表示当天没有操作，相反地dp[i][2]是进行了卖出操作。
 *   有点难理解！不过需要理解了才能写出来状态转移公式。
 * */

//12-20
/*
 * 1.dp[i][0]表示第i天结束之后不持有股票且不处于冷静期   的最大收益！意义要搞清楚好吧
dp[i][1]表示第i天结束之后持有股票
dp[i][2]表示第i天结束之后处于冷冻期且不持有股票
那么状态更新公式：
//这是我原始写的：
 *
dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0],dp[i-1][2])//第三项我真的不确定。。
dp[i][1]=max(dp[i-1][1]], dp[i-1][2]-prices[i])//是2还是0？必须前一天是冷冻期？
dp[i][2]=dp[i-1][0]  //我感觉自己理解的不对，之前做的时候就拐弯抹角地才理解了
更正后：
dp[i][0]=max(dp[i-1][0],dp[i-1][2])
dp[i][1]=max(dp[i-1][1]], dp[i-1][0]-prices[i])//肯定必须不能是冷冻期啊！
dp[i][2]=dp[i-1][1]+prices[i]
边界条件：
dp[0][0]=0 dp[0][1]=-prices[0] dp[0][2]=0
返回结果：
max(dp[0][0],dp[0][2])
复杂度：
O(n),O(n)=>O(1)
 * */

//3-9复习
/*
 * dp[i][0]表示不持有股票，dp[i][1]表示持有股票，dp[i][2]表示第i天处于冷冻期

dp[i][0]=max(dp[i-1][0], dp[i-1][2], dp[i-1]+prices[i]);//前一天没买、前一天处于冷冻期、当天卖出

dp[i][1]=max(dp[i-1][2]-prices[i], dp[i-1][1]);

dp[i][2]=dp[i-1][0];
 复习写的表达式，我还是这个想法，似乎和之前很像，我觉得这种更新方法也可能对吧？
 base case:

 * */
class Solution2 {
public:
    int maxProfit(vector<int>& prices) {
        int m=prices.size();
        if(m==0)return 0;
        vector<vector<int>> dp(m,vector<int>(3,0));
        dp[0][1]=-prices[0];
        for(int i=1;i<m;i++){
            dp[i][0]=max(dp[i-1][0],max(dp[i-1][2], dp[i-1][1]+prices[i]));

            //我忽然明白了，前一天处于卖出状态，那么今天就是冷冻期！！不能买！！没有第二项！！
            //dp[i][1]=max(dp[i-1][2]-prices[i],max(dp[i-1][0]-prices[i],dp[i-1][1]));
            dp[i][1]=max(dp[i-1][2]-prices[i],dp[i-1][1]);
            dp[i][2]=dp[i-1][0];
        }
        for(int i=0;i<m;i++){
        	for(int j=0;j<3;j++)
        		cout<<dp[i][j]<<" ";
        	cout<<"\n";
        }
        return max(dp[m-1][0],dp[m-1][2]);
    }
};
/*
 * 1.AC了！我的想法也对了！！不用硬套官解的解法了终于。。。
 * */
int main(){
	Solution2 s;
	vector<int> prices{1,2,4};
	cout<<s.maxProfit(prices);
    return 0;
}
