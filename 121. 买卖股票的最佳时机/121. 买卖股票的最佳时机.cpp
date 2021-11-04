#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;
//2020��11��17������2:48:52
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //��Ȼ������������ǲ�㲻�ᣬ�����������ˣ����������м�����ͼۣ���ÿ������-������
        if(prices.size()==0) return 0;
        int minp=prices[0],res=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<minp)//�������ֱ�ӻ�Ϊminp=min(minp,prices[i])��򵥡�
                minp=prices[i];
            res=max(res,prices[i]-minp);
        }
        return res;
    }
};//AC��

//12-7��ϰ
//class Solution {
//public:
//    int maxProfit(vector<int>& prices) {
//        //˼�룺dp��ά���飬ÿ�춼������״̬�����л򲻳��У�����õ��������
//        //����dp[i][1]=max(dp[i-1][1],dp[i-1][0]-prices[i])
//        //������dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
//        //��ôĿǰ�ʹ���һ�����⣬��ô����ֻ����һ�Σ�����ס���ˣ���
//        if(prices.size()==0)return 0;
//        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
//        dp[0][0]=0;dp[0][1]=-prices[0];
//        for(size_t i=0;i<prices.size();i++){
//            //�Դ�һƬ�հף���Ϊ����Ϊ�����Ĺ�ʽ���޷����ƽ��״�����
//        }
//    }
//};
/*
 * 1.��θ�ϰ�ҵĸо����ǣ������Ǹ�ɵ�ư���װʲô�ư������أ�mlgb�ġ�
 * 2.�ٷ�����ָ��ı�������O(n^2)�ģ��Ҳ����ף��Ҹ�����û��������������ڽ��ʲô���⣡
 *   ��j>i������ֵ������jҪ��i����ô��ÿ��i���ж�ÿ����j�����˰���
 * */

//12-23
/*
 * 1.̰��˼�룺�Ƚϼ򵥣���ȡһ����Сֵ�����ֵ���������ֵҪ����Сֵ���档��ȡ���Ĳ�ֵ��
	dp�����ᣬ��Ϊ��α�ʾ����һ�ν����أ�
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
};//��Ȼ���������Ľⷨ˼·��һ���İ������˹ٷ���grand������ô��˼·�����˾������ɡ�

//2021-6-18
/*
 * 1.�����ٸ�ϰ����⣬û�뵽�����ȥ�ˣ��һ����벻ͨ��dp��ʱ�����ô���ֻ������һ�ε����⡣
 *
public int maxProfit(int[] prices) {
        if (prices.length < 2) return 0; // û�������Ŀ�����
        // ����״̬����i���������������
        int[] dp = new int[prices.length];
        dp[0] = 0;  // ��ʼ�߽�
        int cost = prices[0]; // �ɱ�
        for (int i = 1; i < prices.length; i++) {
            dp[i] = Math.max(dp[i - 1], prices[i] - cost);
            // ѡ���С�ĳɱ�����
            cost = Math.min(cost, prices[i]);
        }

        return dp[prices.length - 1];
    }
    ���������￴���Ľⷨ��û��ʹ�ö�ά��״̬���飬�ؼ�����ĵ���
	dp[i]��ʾ��i�켰֮ǰ�����ܻ�õ��������
 * */
int main(){

    return 0;
}
