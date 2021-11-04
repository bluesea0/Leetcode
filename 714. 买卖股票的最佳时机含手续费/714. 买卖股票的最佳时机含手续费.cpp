#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��22������3:42:48
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
 * 1.AC�ˣ����ǿ��ٷ������ĺü򵥣�������������˰��������ء�
 *  https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/solution/mai-mai-gu-piao-de-zui-jia-shi-ji-han-shou-xu-fei-/
 *  �ٷ�������ʵ���Ǽ�࣬����Ҫ�м�����洢����Ϊ��fee�Ĵ��ڣ����Բ�����ڵ������뵱�����������
 *  ѧ���ˡ�
 * */

//12-20
/*
 * 1.��Ҫ��д��״̬ת�Ʊ��ʽ��base case�������
���Ӷȣ�O(n)��O(n)
  2.�ٷ����̰��˼����ˣ�
 * */
int main(){

    return 0;
}
