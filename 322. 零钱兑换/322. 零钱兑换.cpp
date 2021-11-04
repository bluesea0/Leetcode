#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//10-19
/*
1.�Ҹо����ѵģ�����ǩ�Ǹ���̬�滮����Ŀ��������ֻ���뵽����DFS�����֡������ñ�����
  ��ôдdp�أ�ת�Ʊ��ʽ����ʲô�أ��Ҹо���û���������ɡ��������ѵġ���
2.����һ˿ӡ���ˣ��϶�Ҫ�ȴӴ�Ŀ�ʼ���𣬵��������ļ����ˣ��������ˣ��ȼ���ÿ��Ӳ�������ٵ�
*/
class Solution {
public:
    int ans=-1;
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),greater<int>());
        ans=amount+1;
        coin(0,0,0,coins,amount);
        return ans==amount+1?-1:ans;
    }
    void coin(int index,int sum,int ct,vector<int> coins, int amount){
        if(sum==amount){
            ans=min(ans,ct);
            return;
        }
        if(index==coins.size())return;
        int k=(amount-sum)/coins[index];
        for(int i=k;i>=0;i--){//���εݼ���
            if(i+ct<ans)//������жϷǳ���Ҫ���Ǽ�֦�����á�
                coin(index+1,sum+i*coins[index],ct+i,coins,amount);
            else break;//�������break֮���ͨ���ˡ���Ȼ���ǻᳬʱ��
        }
    }
};
/*
1.[3,7,405,436]
8839
�����������ʱ�����ơ��ǲ��������forѭ�����ܴ�k->0����Ϊ�������´�����ǳ��ࣿ
���������ÿ��ѭ���Ļ�����ô��֤���Ժ�����ܹ������أ�����һ��ì�ܰ���
[277,196,194,358,263,257]
7477
�޸�֮���������ǻᳬ��ʱ�����ơ�����
[208,170,205,425,124,375]
7130
��������ֳ�ʱ�ˡ��������ˡ�����
2.��������ⷨ��ʵ����dp�ⷨ������DFS+��֦�Ľⷨ��
3.https://leetcode-cn.com/problems/coin-change/solution/322-ling-qian-dui-huan-by-leetcode-solution/
  �ٷ��Ľⷨ���Ҿ��û����Ե����ϱȽϺ���⣬�Զ�������ʵҲ��һ���ݹ顣
*/

//10-22
class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        //dp[i]��ʾ�����ܽ��Ϊiʱ���������Ӳ����Ŀ
        for(int i=1;i<=amount;i++){
            for(auto coin:coins){
                if(i<coin)continue;
                dp[i]=min(dp[i-coin]+1,dp[i]);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];
}};
/*
1.Yes!!AC�ˣ�Ȼ������дһ���Զ����µġ�����������е�ʱ������е㳤�ϡ�
*/
class Solution2 {
public:
    vector<int> dp;
    int coin(vector<int>& coins,int am){//����ʹ������ðɣ���ϣ��coin�����ĵ���˼��
        if(am==0) return 0;
//        if(am<0) return -1;//�����ģ�������ʾ�����޷���ɡ�
        //ע�͵�����������ǿ��Եģ���Ϊ����forѭ�����ڵ���coin��ʱ���������жϡ�
        if(dp[am]!=INT_MAX) return dp[am];
        for(auto c:coins){
            if(am-c>=0){
                int t=coin(coins,am-c);
                if(t>=0)
                    dp[am]=min(dp[am],t+1);
            }
        }
        dp[am]=dp[am]==INT_MAX?-1:dp[am];
        return dp[am];
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount<=0) return 0;//��Ҫ��������жϡ�
        dp.resize(amount+1,INT_MAX);
        coin(coins,amount);
        return dp[amount]==INT_MAX?-1:dp[amount];
    }};
/*
2.[1,2,5]
100������ʱ�����ƣ�������ݹ����д�������Ⱑ������
3.��֮ǰ�����룬�費��Ҫ���򣬵��ǿ���һȦ��û����Ҫ����ġ�
4.{1}��0û��������Ϊʲô�ء�
5.����д������AC�ˣ�̫�������ˣ��ύ��4�β�ͨ�������������Ҫ�ิϰ���Ѿ������ˡ�
*/

//10-23
/*
1.��θ�ϰ����һ�¸��Ӷȣ�O(Sn)������ S�ǽ�n ���������
  ��O(S)��������Ҫ���⿪һ����Ϊ S ���������洢��������Ĵ�
2.������solution2�Ľⷨ���Ƿ�Ҫ��m<0?��t>=0���жϣ���ʵ����Ҫ�ģ������������[2],3������
  ���õĹ����лᵽcoin(1)�������Ļ���Ϊû�н���Ӳ�ҵ�ѭ�����᷵��-1������Ҫ�ж�t>=0
  �����ֱ��dp�������޸ķ��ص�ֵ��������-1����ô��ִ��[2],3��ʱ��ͻ�����NT_MAX+1���������
  ���԰����ҵĳ�ʼ���������ͱ��밴���������д����ͦ�鷳�ģ��ҿ����ٷ�����ôд��
  �ٷ���д�����һ���һ�£�������Ҫ�ж�amount<0?�򷵻�-1��Ȼ��Ҫ�Է��ص�ֵ�ж�>0����������Դղ�
  �ϵ�������
*/

//2-20
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        //�Ҿ�д����򵥵���ȫ�����ɣ����Ż��ռ�Ľⷨ
//        //����Ҫ����ռ�Ļ����Ҿ��е㺦���ˣ��᲻��ռ䲻���ã���Ϊamount���ֵΪ10000
//        if(amount==0) return 0;
//        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
//        //dp[i][j]��ʾ��[0,i]��Ӳ������ͳ�amount������Ӳ�Ҹ���
//        //״̬ת�Ʒ��̣�dp[i][j]=min(dp[i-1][j-k*nums[i]]+k) k�Ĵ�С��֤�±�ֵΪ��
//        //base case��dp[i][0]=0,
//        //�ǰ�����ô˵��������ѭ���ˣ�
//    }
//};
class Solution4 {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0) return 0;
        //vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        //��ȫ��������û����Ʒ��״̬��ֻ��������
        //dp[i]��ʾ����Ϊiʱ���������Ӳ�Ҹ���,dp[i]=min(dp[i-coins[j]]+1)
        //��ʵ��������������϶�����j-weight[i]���������Ƶģ�
        vector<int> dp(amount+1,amount+1);//��ʾ��඼����1��ɵ�
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]>i)continue;
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
            }
        }
        return dp[amount]==amount+1?-1:dp[amount];//��������Ҫ�����鲻�ɵ����
    }
};
/*
 * 1.������ȫ����д��AC�ˣ���̫�����˰������ء��Ҿ��þ��������ˣ����˹��ˡ�
 * */

//6-11
//class Solution {
//public:
//    int coinChange(vector<int>& coins, int amount) {
//        /*
//        dp[i][j]��ʾǰi��Ӳ�������j�ܶ������Ӳ�Ҹ���
//        dp[i][j]=min(dp[i-1][j],dp[i-1][j-k*nums[i-1]]);
//        */
//        int n=coins.size();
//        vector<vector<int>> dp(n+1,vector<int>(amount+1,amount+1));
//        //dp[0][0]=0;
//        for(int i=0;i<=n;i++)
//            dp[i][0]=0;
//        for(int i=1;i<=n;i++){
//            for(int j=1;j<=amount;j++){
//                if(coins[i-1]>j)dp[i][j]=dp[i-1][j];
//                else dp[i][j]=min(dp[i-1][j],dp[i-1][j-coins[i-1]]+1);
//            }
//        }
//        return dp[n][amount];
//    }
//};
/*
 * 1.д��д��ûд�������ѵ�����ȫ���������ֻ��dp[j]��ʾamount�ͺ��ˣ���Ϊ��ȫ������ά�Ĳ��ý����
 *   ����ת��Ϊһά�ģ�ʹ��01�����������̫���ˡ�
 * */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        vector<int> dp(amount+1,amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(auto& c:coins){
                if(c>i)continue;
                dp[i]=min(dp[i],dp[i-c]+1);
            }
        }
        return dp.back()==amount+1?-1:dp.back();
    }
};
/*
 * 1.�����ָ�����ȫ������˼��������ˡ�̫�������ˡ�
 * */

//9-18
/*
 * 1.0-1�������⣬��������Ʒ���ڲ�Ӵ�С��������������Ϊֻ����һ�Σ�
 *   ��ȫ�������⣬��������Ʒ���ڲ��С������������������ö�Σ�
 * */
int main(){
    Solution4 s;
    vector<int> v={2};
    cout<<s.coinChange(v,3);//�����������Ļ������Բ��ϣ�Ȼ��ͻ���ѭ���ˣ�û�г��ڣ�����Ҫ���һ��
    return 0;
}
