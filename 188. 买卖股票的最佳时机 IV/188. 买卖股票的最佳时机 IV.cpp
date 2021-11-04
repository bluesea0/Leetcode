#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2020��12��28������3:06:43
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        //��Ʊϵ����ֻ����һ���ˡ�
        if(prices.size()==0)return 0;
        if(k>prices.size()/2){//������ʵ�Ҳ�̫����Ϊʲôû��=�ţ�
            //Ҳ����˵�������������5�Ļ�����ôk���ٵ���3������ʵ��Ҳ���в���3�ν��׵�
            //oh���뵽��ֻҪ�������3��
            //�����������������ˣ��Ǿ�ͨ��̰��������������
            int ans=0;
            for(int i=1;i<prices.size();i++){//������ô�򵥣�
                if(prices[i]>prices[i-1])
                    ans+=(prices[i]-prices[i-1]);
            }
            return ans;
        }else{
            //C++��ô������ά�����أ�
            int m=prices.size();
            vector<vector<vector<int>>> dp(m,vector<vector<int>>(k+1,vector<int>(2,0)));//��ʼ��ά�ȴ�СΪm*k*2.
            //dp[0][1][1]=-prices[0];//���ģ���ⲻȫ������߽��������д������
            //dp[0][1][0]=INT_MIN;
            for(int i=1;i<=k;i++){
            	dp[0][i][0]=0;
            	dp[0][i][1]=-prices[0];//��0�첻���ǽ��׼��ζ���
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
 * 1.�����ֶ�����һ�������ɣ���Ȼ�ҿ����Ⱳ�Ӷ��㲻�����ˡ�
 *   i=1: j=1: dp[1][1][0]=max(dp[0][1][0],dp[0][1][1]+2)=max(0,-1+2)=1;
 *   		   dp[1][1][1]=max(dp[0][1][1],dp[0][0][0]-2)=max(-1,0-2)=-1;
 *   	  j=2:
 * 2.���ղ����������д�ˣ�https://blog.csdn.net/hushaoqiqimingxing/article/details/94218892
 * 	 �߽�������Ҫ������ʼ����
 * 	        for(int i=1;i<=k;i++){
            	dp[0][i][0]=0;
            	dp[0][i][1]=-prices[0];//��0�첻���ǽ��׼��ζ���
            }//������Ҳ̫���˰ɣ�̫�е����ˣ�ֻҪ�ǵ�0�죬��ô���ܽ��׼�������й�Ʊ�Ļ��Ǿ���
 * */
int main(){
	Solution s;
	vector<int> prices{1,2,4,2,5,7,2,4,9,0};
	cout<<s.maxProfit(4, prices);
    return 0;
}
