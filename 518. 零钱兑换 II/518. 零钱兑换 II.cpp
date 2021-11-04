#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��20������4:36:50
//class Solution {
//public:
//    int change(int amount, vector<int>& coins) {
//        //��ʵ�����322�ǳ���ֻ������������Сֵ���������������
//        //dp[i]+=dp[i-c]
//        //���������ԣ�������д��������������Ҳ������������ҿ��ˣ�
//
//        //dp[i]=max(dp[i],dp[i-c])???������������Ҳ���ԣ������Ļ���ô�����أ�
//        //������Ĳ����ˣ�
//
//        vector<int> dp(amount+1,0);
//        dp[0]=1;//���︳ֵΪ1��ʾ����м����������ֵ��ʾ����1������ʾ������
//        for(int i=1;i<=amount;i++){//û����ʶ�������л���������⣬����ͷһ��ѧ��
//            for(auto c:coins){
//                if(c>i)continue;
//                //if(dp[i]==INT_MAX)//����ĳ�ʼ���ƺ�����������
//                    //dp[i]=1;//�����Ǽ������м��֣��������������ɼ����γ�
//                //�ؼ�����״̬���̵ĸ���
//                //dp[i]+=dp[i-c];
//                dp[i]=max(dp[i],dp[i-c]);
//            }
//        }
//        return dp[amount]==INT_MAX?0:dp[amount];
//    }
//};
/*
 * 1.������⣺����Ʒ��������ѭ����������⣬��������������ѭ�����������⣡
 * 2.��70����¥�����ƣ�����70���������⣬������������⡣
 * */
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        dp[0]=1;//���︳ֵΪ1��ʾ����м����������ֵ��ʾ����1������ʾ������
        for(auto& c:coins){//����ȱ�����=�̶���Ӳ�ҵĴ�С˳�����������
            for(int i=1;i<=amount;i++){//�����i����ֱ�ӳ�ʼ��Ϊc����ʡ��д�����continue����ˣ�����
                if(c>i)continue;
                dp[i]+=dp[i-c];
            }
        }
        return dp[amount];
    }
};
/*
 * 3.AC�ˣ�https://www.cnblogs.com/grandyang/p/7669088.html���ｲ�˳�ʼδ�Ż��ķ��̣�
 *   dp[i][j] = dp[i - 1][j] + (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0)
 *   i��ö��Ӳ�ң�����ǰ����j��ʱ�򣬽����������������ǰӲ��ʱ���j����Ŀ+������ǰӲ��iʱ���j����Ŀ
 * */

//3-25
/*
 * 1.�������Ѷȵģ�����Ʒ�������ѭ����ÿ������ֻ���һ�Σ��Ǹ�������⣻����Ʒ�����ڲ�ѭ����ÿ�����������
 *   ÿ����Ʒ��һ�Σ�������֮ǰ�������Ѿ������˸���Ʒ�����Ծ����������⡣
 * */

//6-11
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        //�ȱ���Ӳ�ұ�֤���ظ���ÿ�ֽ����ֵ�˳����̶���
        if(amount==0)return 1;
        vector<int> dp(amount+1,0);
        dp[0]=1;
        for(auto &c:coins){
            for(int i=1;i<=amount;i++){
                if(c>i)continue;
                dp[i]=dp[i]+dp[i-c];
            }
        }
        return dp.back();
    }
};//����Ҫ�ิϰ����
int main(){

    return 0;
}
