#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020年12月28日下午3:06:43
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //股票系列题只差这一个了。
        if(prices.size()==0)return 0;
        if(k>prices.size()/2){//这里其实我不太明白为什么没有=号？
            //也就是说如果是奇数，是5的话，那么k至少得是3？但其实它也进行不了3次交易的
            //oh我想到了只要买入就是3。
            //那这样就是无限制了，那就通过贪心求连续递增和
            int ans=0;
            for(int i=1;i<prices.size();i++){//就是这么简单？
                if(prices[i]>prices[i-1])
                    ans+=(prices[i]-prices[i-1]);
            }
            return ans;
        }else{
            //C++怎么定义三维数组呢？
            int m=prices.size();
            vector<vector<vector<int>>> dp(m,vector<vector<int>>(k+1,vector<int>(2,0)));//初始化维度大小为m*k*2.
            //dp[0][1][1]=-prices[0];//天哪，理解不全，这里边界情况根本写不出来
            //dp[0][1][0]=INT_MIN;
            for(int i=1;i<=k;i++){
            	dp[0][i][0]=0;
            	dp[0][i][1]=-prices[0];//第0天不管是交易几次都是
            }
            for(int i=1;i<m;i++){
                for(int j=k;j>=1;j--){
                    dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]+prices[i]);
                    dp[i][j][1]=max(dp[i-1][j][1],dp[i-1][j-1][0]-prices[i]);
                    cout<<i<<" "<<j<<" "<<dp[i][j][0]<<" "<<dp[i][j][1]<<endl;
                }
            }
            return dp[m-1][k][0];
        }
    }
};
/*
 * 1.我来手动运行一下这道题吧，不然我可能这辈子都搞不明白了。
 *   i=1: j=1: dp[1][1][0]=max(dp[0][1][0],dp[0][1][1]+2)=max(0,-1+2)=1;
 *   		   dp[1][1][1]=max(dp[0][1][1],dp[0][0][0]-2)=max(-1,0-2)=-1;
 *   	  j=2:
 * 2.最终参照这个代码写了：https://blog.csdn.net/hushaoqiqimingxing/article/details/94218892
 * 	 边界条件是要这样初始化：
 * 	        for(int i=1;i<=k;i++){
            	dp[0][i][0]=0;
            	dp[0][i][1]=-prices[0];//第0天不管是交易几次都是
            }//天哪这也太难了吧，太有道理了，只要是第0天，那么不管交易几次如果有股票的话那就是
 * */
int main(){
	Solution s;
	vector<int> prices{1,2,4,2,5,7,2,4,9,0};
	cout<<s.maxProfit(4, prices);
    return 0;
}
