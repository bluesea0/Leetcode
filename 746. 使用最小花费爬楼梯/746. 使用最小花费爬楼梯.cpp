#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��21������1:41:00
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),0);
        int m=dp.size();
        dp[0]=cost[0];
        dp[1]=cost[1];//dp[i]��ʾ����������ǰΪֹ����ͻ��ѣ��Ǹ�������
        for(int i=2;i<m;i++){
            //ѡ�񣺴�i-2��2������ǰλ��
            // ��i-1��1������ǰλ��
            // ��i-1��2������һλ�ã��������������һλ����ô�����أ���һ���Ӿͼ�����һλ�ã�
            //��Ӧ�ü�
            //dp[i]=min(min(dp[i-2]+cost[i],dp[i-1]+cost[i]),dp[i-1]);//���������ôд�Ļ�
            //�Ͳ��ñȽ�ʲô�ˣ��������϶�Ҫ�ڶ���С�İ���
            //���һ���һ�����⣺����1������2�����������ˣ�����2�������������һ��Ԫ����
            //�����ֲ�������������ж��أ����Զ������Ƿ���У�
            dp[i]=min(dp[i-1]+cost[i],dp[i-2]+cost[i]);
        }
        return min(dp[m-1],dp[m-2]);
    }
};//AC�ˣ��ȽϿ��ģ����������л�����������⣬��Ҫ�Ƕ�����ķ�����͸�����µġ�

class Solution1 {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //���пռ���Ż�
        int dp0=cost[0],dp1=cost[1];
        for(int i=2;i<cost.size();i++){
            int t1=min(dp0+cost[i],dp1+cost[i]);
            dp0=dp1;
            dp1=t1;
        }
        return min(dp0,dp1);
    }
};//�Ҷ������ǡ�����
int main(){

    return 0;
}
