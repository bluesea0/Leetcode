#include <iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;
//2021��10��8������10:26:09
class Solution {
public:
    int minInsertions(string s) {
        //�൱���������������
        //������������
        //dp[i][j]��ʾs[i:j]������Ӵ�
        //dp[0][n-1]��ʾs[0:n-1]��������Ӵ�
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i=n-1;i>=0;i--){
            dp[i][i]=1;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j])dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return n-dp[0][n-1];
    }
};
/*
 * 1.�ٷ�����У��Ҳ�̫��Ϊʲô����dpʱ��״̬ת��ʱΪʲôҪ����������ѧϰһ������dp�Ľⷨ��
 * */

//10-10
class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int len=2;len<=n;len++){//����dp��ö�ٳ���
            for(int i=0;i+len<=n;i++){
                int j=i+len-1;
                if(s[i]==s[j])dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=min(dp[i+1][j],dp[i][j-1])+1;//��i�в���s[j]������j�в���s[i]
            }
        }
        return dp[0][n-1];//dp[i][j]��ʾ��s��[i,j]֮��
    }
};
/*
 * 1.����dp�Ľⷨ��ö��len����㣬Ȼ�����j��Ҳ���ǱȽϺ���⣬������Ҫ�����⹮�̲��С�
 * */
int main(){

    return 0;
}
