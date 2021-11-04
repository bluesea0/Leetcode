#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��2��17������4:57:22
//class Solution {
//public:
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        //dp[i][j]��ʾ������i��0��j��1������£������Ӽ���С
//        //��ʵ��һ���������������strs��ǰn��Ԫ��������м���0����1����������3ά���飬������
//        //����Ҫ��strs.size()�У�m���У�Ȼ�����ά��n���ͱ�ʾ��ǰi��Ԫ������������j��0��k��1
//        //������������ֻ��ʵ��һ�������Ĺ��ܣ�ֻ�Ƕ�ÿ��Ԫ�ص�0��1��Ŀͳ����һ��
//        //��ʵ����m��n���൱��������������
//    }
//};
/*
 * 1.����Ϊ������ķ��������أ�û�뵽û����ȷʵ��û��ģ��ο�https://www.cnblogs.com/grandyang/p/6188893.html
 *   ��������һ¥�ⷨ��״̬���������ģ���Ʒ������0������1��������ʵ�Ǹ���ά�����⣬֮��Ŀռ��Ż�
 *   ת��Ϊ��ά����������0-1��������������Ҫ�Ӵ�С���¡�dp[i][j][k]��ʾ��������[0,i]����j��0k��1��
 *   �ַ������������������ʵ���ʱ�����������j��������k��Ҳ�п��ܶ����㣬ֻ������������������
 *   �����ǻ���ǣ�Ƶġ�
 * */
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //dp[i][j][k]=max(dp[i-1][j-x][k-y]+1,dp[i-1][j][k]);//�Ż��߲���
        //�Ż��ռ��0-1����������Ҫ�������
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<strs.size();i++){//����ÿ����Ʒ���Ƿ��ܷŽ�ȥ
            auto ct=helper(strs[i]);
            for(int j=m;j>=0;j--){//��Ӧ0�ĸ���
                for(int k=n;k>=0;k--){//��Ӧ1�ĸ���
                    if(j>=ct[0]&&k>=ct[1])
                        dp[j][k]=max(dp[j][k],dp[j-ct[0]][k-ct[1]]+1);
                        //ÿ�����涼Ҫ����������ĸ��£�������ά�����ֶ����һ��
                        //������»����ģ�
                    else break;
                }
            }
        }
        return dp[m][n];
    }
    vector<int> helper(string& s){
        int x=0,y=0;
        for(auto& c:s){
            if(c=='0')x++;
            else y++;
        }
        return {x,y};
    }
};
/*
 * 1.0-1�����ⷨʵ�����е��Ѱ������ӶȾ�������forѭ���˻�
 * */
int main(){

    return 0;
}
