#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020年11月22日下午3:42:48
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        size_t m=prices.size();
        vector<vector<int>> dp(m,vector<int>(2,0));
        dp[0][1]=-(prices[0]+fee);
        for(size_t i=1;i<m;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]-fee);
        }
        return dp[m-1][0];
    }
};
/*
 * 1.AC了，但是看官方解答，真的好简单，比我这个简洁多了啊，呜呜呜。
 *  https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-han-shou-xu-fei-/
 *  官方解答给的实在是简洁，不需要中间变量存储，因为有fee的存在，所以不会存在当天买入当天卖出的情况
 *  学到了。
 * */

//12-20
/*
 * 1.主要是写出状态转移表达式，base case基本情况
复杂度：O(n)、O(n)
  2.官方解的贪心思想绝了！
 * */
int main(){

    return 0;
}
