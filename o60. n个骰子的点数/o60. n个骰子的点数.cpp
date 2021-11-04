#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;
//2021年3月22日下午3:30:07
class Solution {
public:
    vector<double> dicesProbability(int n) {
        //dp[i][j]表示扔完第i个骰子后，前i个骰子点数和为j的次数
        //那么它有六种情况，dp[i][j]=k求和(dp[i-1][j-k])
        //但是我还有个隐藏的问题是，如果n=4的话，那么最小的和s应该是4，那1-3？该如何处理呢？
        //是在返回的时候取值？这个地方我有点疑问了。
        vector<vector<int>> dp(n+1,vector<int>(6*n+1,0));//下标都从1开始计算
        //其实用不了二维的，一维的就够
        //base case：
        for(int i=1;i<=6;i++)
            dp[1][i]=1;
        for(int i=2;i<=n;i++){//针对第几个骰子
            for(int j=i;j<=6*i;j++){
                //投掷完第i个骰子后和为j，起始值为j，终止为i个骰子和的最大值
                for(int k=1;k<=6;k++){//第i个骰子投掷的结果
                if(j-k<=0)break;
                dp[i][j]+=dp[i-1][j-k];
                }
            }
        }
        //怎么由int转换为double呢？
        //总共可能的投掷结果有6*n-n个
        vector<double> ans;
        //int all=6*n-n+1;//这里我理解错了，不是计算结果多长，而是计算所有总的次数
        int all=pow(6,n);
        for(int i=n;i<=6*n;i++)
            ans.push_back(dp[n][i]*1.0/all);
        return ans;
    }
};
/*
 * 1.没想到用动态规划，还是挺难的啊。可以进行空间优化。空间优化还得考虑一下更新顺序是从后到前，还是从前到后？
 * 2.
 * */
class Solution2 {
public:
    vector<double> dicesProbability(int n) {
        vector<int> dp(6*n+1,0);
        for(int i=1;i<=6;i++)
            dp[i]=1;
        for(int i=2;i<=n;i++){
            vector<int> temp(6*n+1,0);
            for(int j=i;j<6*n+1;j++){
                for(int k=1;k<=6;k++){
                    if(k>=j)break;
                    temp[j]+=dp[j-k];
                }
            }
            dp=temp;
        }
        vector<double> ans;
        int all=pow(6,n);
        for(int i=n;i<=6*n;i++)
            ans.push_back(dp[i]*1.0/all);
        return ans;
    }
};
/*
 * 1.上面经过空间优化的也AC了，但是我看题解，它是从后往前更新，这样就不用临时数组了。
 * 2.不搞了，就这样子我觉得效率就挺高的了，而且好理解。
 * */
int main(){
	Solution2 s;
	vector<double> ans=s.dicesProbability(2);
	for(auto r:ans)
		cout<<r<<" ";
    return 0;
}
