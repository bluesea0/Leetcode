#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��22������1:33:57
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //����״̬�����С�û���С��䶳��
        size_t m=prices.size();
        if(m==0) return 0;
        vector<vector<int>> dp(m,vector<int>(3,0));//[m,3]
        //base case
        dp[0][1]=-prices[0];//��0����й�Ʊ
        // dp[0][2]=0;//��0�촦���䶳�ڣ����ǲ����ܵ�
        for(size_t i=1;i<m;i++){
            //��i�첻���й�Ʊ�Ҳ������䶳�ڣ�˵��i-1�첻���й�Ʊ
            //��ô����i-1�촦���䶳�ڣ�i-1�첻�����䶳��
            dp[i][0]=max(dp[i-1][2],dp[i-1][0]);

            //��i����й�Ʊ
            //i-1��Ҳ���й�Ʊ��i-1�첻�����Ҳ������䶳��
            dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i]);

            //��i����й�Ʊ���ҵ�����������ô��i-1��ʹ����䶳����
            dp[i][2]=dp[i-1][1]+prices[i];//����������䶳����ô���£���Ӧ���Ǳ����İ�
            //����˵������ô�鷳��dp�⣬����ô������������
        }
        return max(dp[m-1][0],dp[m-1][2]);//��������
    }
};
/*
 * 1.AC�ˣ�������˵�����ĺ��Ѱ���
 *   https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4/
 *   �ٷ����д�ķǳ��ã�����ʵ�����������֮����ûд��������Ҫ�Ƕ�dp����ı�ʾ���ǲ��������������⡣
 * 2.�����䶳�ڣ�dp[i][2]�����䶳�ڱ�ʾ���ǵ�i��������״̬����i�����֮���״̬����i+1�첻�����Ʊ
 *   ��ôdp[i][0]��ʾ�������䶳�ڣ���ʾ����û�в������෴��dp[i][2]�ǽ���������������
 *   �е�����⣡������Ҫ����˲���д����״̬ת�ƹ�ʽ��
 * */

//12-20
/*
 * 1.dp[i][0]��ʾ��i�����֮�󲻳��й�Ʊ�Ҳ������侲��   ��������棡����Ҫ������ð�
dp[i][1]��ʾ��i�����֮����й�Ʊ
dp[i][2]��ʾ��i�����֮�����䶳���Ҳ����й�Ʊ
��ô״̬���¹�ʽ��
//������ԭʼд�ģ�
 *
dp[i][0]=max(dp[i-1][1]+prices[i],dp[i-1][0],dp[i-1][2])//����������Ĳ�ȷ������
dp[i][1]=max(dp[i-1][1]], dp[i-1][2]-prices[i])//��2����0������ǰһ�����䶳�ڣ�
dp[i][2]=dp[i-1][0]  //�Ҹо��Լ����Ĳ��ԣ�֮ǰ����ʱ��͹���Ĩ�ǵز������
������
dp[i][0]=max(dp[i-1][0],dp[i-1][2])
dp[i][1]=max(dp[i-1][1]], dp[i-1][0]-prices[i])//�϶����벻�����䶳�ڰ���
dp[i][2]=dp[i-1][1]+prices[i]
�߽�������
dp[0][0]=0 dp[0][1]=-prices[0] dp[0][2]=0
���ؽ����
max(dp[0][0],dp[0][2])
���Ӷȣ�
O(n),O(n)=>O(1)
 * */

//3-9��ϰ
/*
 * dp[i][0]��ʾ�����й�Ʊ��dp[i][1]��ʾ���й�Ʊ��dp[i][2]��ʾ��i�촦���䶳��

dp[i][0]=max(dp[i-1][0], dp[i-1][2], dp[i-1]+prices[i]);//ǰһ��û��ǰһ�촦���䶳�ڡ���������

dp[i][1]=max(dp[i-1][2]-prices[i], dp[i-1][1]);

dp[i][2]=dp[i-1][0];
 ��ϰд�ı��ʽ���һ�������뷨���ƺ���֮ǰ�����Ҿ������ָ��·���Ҳ���ܶ԰ɣ�
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

            //�Һ�Ȼ�����ˣ�ǰһ�촦������״̬����ô��������䶳�ڣ��������򣡣�û�еڶ����
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
 * 1.AC�ˣ��ҵ��뷨Ҳ���ˣ�������Ӳ�׹ٽ�Ľⷨ�����ڡ�����
 * */
int main(){
	Solution2 s;
	vector<int> prices{1,2,4};
	cout<<s.maxProfit(prices);
    return 0;
}
