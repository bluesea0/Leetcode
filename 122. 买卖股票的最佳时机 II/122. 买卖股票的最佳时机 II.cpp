#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��17������2:54:41
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //˼·���൱�ڼ������������е��������еĺ�
        int ans=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
                ans+=(prices[i]-prices[i-1]);
        }
        return ans;
    }
};//AC�ˣ���Ȼ����Ϊ��֮ǰ������⣬�����Ļ����ǲ����ġ������̰�ĵķ���������dp�ķ�����

class Solution1 {
public:
    int maxProfit(vector<int>& prices) {
        //˼·��ʹ��dp�Ļ�����Ҫ��״̬��dp[i][0]��ʾ��i�첻���й�Ʊ���������
        //dp[i][1]��ʾ��i����й�Ʊ���������
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        dp[0][0]=0;dp[0][1]=-prices[0];
        for(int i=1;i<n;i++){
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i]);//ǰһ��û�У�ǰһ���н�������
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);//ǰһ���У�ǰһ��û�н�����
        }
        return dp[n-1][0];
    }
};
/*
 * 1.ʹ��dp�ķ�������Ȼ����������ʵ�ǲ��ö�ά����ģ�ֻ���¼��һ�������״̬��
 * */
class Solution3 {
public:
    int maxProfit(vector<int>& prices) {
        //˼·��ʹ��dp�Ļ�����Ҫ��״̬��dp[i][0]��ʾ��i�첻���й�Ʊ���������
        //dp[i][1]��ʾ��i����й�Ʊ���������
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int>(2,0));
        int dp0=0,dp1=-prices[0];
        for(int i=1;i<n;i++){
            int d0=max(dp0,dp1+prices[i]);
            int d1=max(dp1,dp0-prices[i]);
            dp0=d0;
            dp1=d1;
        }
        return dp0;
    }
};//���ʵ����ͦ���ģ�
int main(){

    return 0;
}
