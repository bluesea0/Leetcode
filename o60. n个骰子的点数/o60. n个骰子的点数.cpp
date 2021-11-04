#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include<cmath>
using namespace std;
//2021��3��22������3:30:07
class Solution {
public:
    vector<double> dicesProbability(int n) {
        //dp[i][j]��ʾ�����i�����Ӻ�ǰi�����ӵ�����Ϊj�Ĵ���
        //��ô�������������dp[i][j]=k���(dp[i-1][j-k])
        //�����һ��и����ص������ǣ����n=4�Ļ�����ô��С�ĺ�sӦ����4����1-3������δ����أ�
        //���ڷ��ص�ʱ��ȡֵ������ط����е������ˡ�
        vector<vector<int>> dp(n+1,vector<int>(6*n+1,0));//�±궼��1��ʼ����
        //��ʵ�ò��˶�ά�ģ�һά�ľ͹�
        //base case��
        for(int i=1;i<=6;i++)
            dp[1][i]=1;
        for(int i=2;i<=n;i++){//��Եڼ�������
            for(int j=i;j<=6*i;j++){
                //Ͷ�����i�����Ӻ��Ϊj����ʼֵΪj����ֹΪi�����Ӻ͵����ֵ
                for(int k=1;k<=6;k++){//��i������Ͷ���Ľ��
                if(j-k<=0)break;
                dp[i][j]+=dp[i-1][j-k];
                }
            }
        }
        //��ô��intת��Ϊdouble�أ�
        //�ܹ����ܵ�Ͷ�������6*n-n��
        vector<double> ans;
        //int all=6*n-n+1;//�����������ˣ����Ǽ������೤�����Ǽ��������ܵĴ���
        int all=pow(6,n);
        for(int i=n;i<=6*n;i++)
            ans.push_back(dp[n][i]*1.0/all);
        return ans;
    }
};
/*
 * 1.û�뵽�ö�̬�滮������ͦ�ѵİ������Խ��пռ��Ż����ռ��Ż����ÿ���һ�¸���˳���ǴӺ�ǰ�����Ǵ�ǰ����
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
 * 1.���澭���ռ��Ż���ҲAC�ˣ������ҿ���⣬���ǴӺ���ǰ���£������Ͳ�����ʱ�����ˡ�
 * 2.�����ˣ����������Ҿ���Ч�ʾ�ͦ�ߵ��ˣ����Һ���⡣
 * */
int main(){
	Solution2 s;
	vector<double> ans=s.dicesProbability(2);
	for(auto r:ans)
		cout<<r<<" ";
    return 0;
}
